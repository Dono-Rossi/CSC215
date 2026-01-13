#include <stdio.h>
#include "BIGINT.H"

void set_bigint(numstr, num)
char *numstr;
struct bigint *num;
{
    char last_pos, i;
    num->negative = (numstr[0] == '-');
    num->numdigits = strlen(numstr) - num->negative;
    num->digits = alloc(num->numdigits);
    last_pos = num->numdigits + (num->negative ? 0 : -1);

    for (i = 0; i < num->numdigits; i++) {
        num->digits[i] = numstr[last_pos-i];
        /* printf("numstr[%d] is %c\n", last_pos-i, numstr[last_pos-i]); */
    }
}

char* get_bigint(num)
struct bigint *num;
{
   char *numstr;
   char start_pos, i;
   numstr = alloc(num->numdigits + (num->negative ? 2 : 1));
   start_pos = num->negative;
   if (start_pos == 1) numstr[0] = '-';
   for (i = 0; i < num->numdigits; i++) {
       numstr[i+start_pos] = num->digits[num->numdigits-(i+1)];
       /* printf("numstr[%d] is %c\n", i, numstr[i+start_pos]); */
   }
   numstr[num->numdigits+start_pos] = '\0';
   return numstr;
}

void add_bigint(bi1,bi2,biout)
struct bigint *bi1;
struct bigint *bi2;
struct bigint *biout;
{
    char cmp;

    /* Same-sign: just add magnitudes and set sign */
    if (bi1->negative == 0 && bi2->negative == 0) {
        add_abs(bi1, bi2, biout);
        biout->negative = 0;
        return;
    } else if (bi1->negative == 1 && bi2->negative == 1) {
        add_abs(bi1, bi2, biout);
        biout->negative = 1;
        return;
    }

    /* Different signs: perform magnitude subtraction and pick sign by magnitude */
    if (bi1->negative == 0 && bi2->negative == 1) {
        /* (+A) + (-B) => A - B */
        cmp = compare_abs(bi1, bi2);
        if (cmp == 0) {
            biout->digits = alloc(1);
            biout->digits[0] = '0';
            biout->numdigits = 1;
            biout->negative = 0;
            return;
        } else if (cmp > 0) {
            /* |bi1| > |bi2| => positive result */
            sub_abs(bi1, bi2, biout);
            biout->negative = 0;
            return;
        } else {
            /* |bi2| > |bi1| => negative result */
            sub_abs(bi2, bi1, biout);
            biout->negative = 1;
            return;
        }
    } else {
        /* bi1 negative, bi2 positive: (-A) + B => B - A */
        cmp = compare_abs(bi2, bi1);
        if (cmp == 0) {
            biout->digits = alloc(1);
            biout->digits[0] = '0';
            biout->numdigits = 1;
            biout->negative = 0;
            return;
        } else if (cmp > 0) {
            /* |bi2| > |bi1| => positive result */
            sub_abs(bi2, bi1, biout);
            biout->negative = 0;
            return;
        } else {
            /* |bi1| > |bi2| => negative result */
            sub_abs(bi1, bi2, biout);
            biout->negative = 1;
            return;
        }
    }
}

void sub_bigint(bi1, bi2, biout)
struct bigint *bi1;
struct bigint *bi2;
struct bigint *biout;
{
    
    char s1;
    char s2;
    char cmp;

    s1 = bi1->negative;
    s2 = bi2->negative;

    /* Case analysis on signs:
       R = bi1 - bi2
       if s1==0 && s2==0: R = |bi1| - |bi2|
       if s1==0 && s2==1: R = |bi1| + |bi2|
       if s1==1 && s2==0: R = - (|bi1| + |bi2|)
       if s1==1 && s2==1: R = |bi2| - |bi1|  (because -|bi1| - (-|bi2|) = |bi2|-|bi1|)
    */

    if (s1 == 0 && s2 == 0) {
        /* |bi1| - |bi2| */
        cmp = compare_abs(bi1, bi2);
        if (cmp == 0) {
            /* zero */
            biout->digits = alloc(1);
            biout->digits[0] = '0';
            biout->numdigits = 1;
            biout->negative = 0;
            return;
        } else if (cmp > 0) {
            sub_abs(bi1, bi2, biout);
            biout->negative = 0;
            return;
        } else {
            sub_abs(bi2, bi1, biout);
            biout->negative = 1;
            return;
        }
    } else if (s1 == 0 && s2 == 1) {
        /* |bi1| + |bi2| */
        add_abs(bi1, bi2, biout);
        biout->negative = 0;
        return;
    } else if (s1 == 1 && s2 == 0) {
        /* -(|bi1| + |bi2|) */
        add_abs(bi1, bi2, biout);
        biout->negative = 1;
        return;
    } else { /* s1 == 1 && s2 == 1 */
        /* |bi2| - |bi1| */
        cmp = compare_abs(bi2, bi1);
        if (cmp == 0) {
            biout->digits = alloc(1);
            biout->digits[0] = '0';
            biout->numdigits = 1;
            biout->negative = 0;
            return;
        } else if (cmp > 0) {
            sub_abs(bi2, bi1, biout);
            biout->negative = 0; /* positive result */
            return;
        } else {
            sub_abs(bi1, bi2, biout);
            biout->negative = 1;
            return;
        }
    }
}

void add_abs(bi1, bi2, biout)
struct bigint *bi1;
struct bigint *bi2;
struct bigint *biout;
{
    char maxdigits, i, carry, digit1, digit2, sum;
    maxdigits = (bi1->numdigits > bi2->numdigits) ? bi1->numdigits : bi2->numdigits;
    biout->digits = alloc(maxdigits + 1);
    carry = 0;

    for (i = 0; i < maxdigits; i++) {
        if (i < bi1->numdigits) {
            digit1 = bi1->digits[i] - '0';
        } else {
            digit1 = 0;
        }

        if (i < bi2->numdigits) {
            digit2 = bi2->digits[i] - '0';
        } else {
            digit2 = 0;
        }

        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        biout->digits[i] = (sum % 10) + '0';
    }

    if (carry > 0) {
        biout->digits[maxdigits] = carry + '0';
        biout->numdigits = maxdigits + 1;
    } else {
        biout->numdigits = maxdigits;
    }
    /* ensure no leading zeros in representation (shouldn't be any) */
    if (biout->numdigits == 0) {
        biout->numdigits = 1;
        biout->digits[0] = '0';
    }
}

char* compare_abs(bi1, bi2)
struct bigint *bi1;
struct bigint *bi2;
{
    char i;
    if (bi1->numdigits > bi2->numdigits) return 1;
    if (bi1->numdigits < bi2->numdigits) return -1;
    for (i = bi1->numdigits - 1; i >= 0; i--) {
        if (bi1->digits[i] > bi2->digits[i]) return 1;
        if (bi1->digits[i] < bi2->digits[i]) return -1;
        if (i == 0) break; /* avoid underflow of char when 0 */
    }
    return 0;
}

void sub_abs(larger, smaller, biout)
struct bigint *larger;
struct bigint *smaller;
struct bigint *biout;
{
    char i, borrow, d1, d2, diff;
    biout->digits = alloc(larger->numdigits);
    borrow = 0;

    for (i = 0; i < larger->numdigits; i++) {
        d1 = larger->digits[i] - '0';
        if (i < smaller->numdigits) {
            d2 = smaller->digits[i] - '0';
        } else {
            d2 = 0;
        }
        diff = d1 - d2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        biout->digits[i] = diff + '0';
    }

    /* trim leading zeros (most significant digits) */
    for (i = larger->numdigits - 1; i > 0; i--) {
        if (biout->digits[i] != '0') break;
        /* continue trimming */
    }
    biout->numdigits = i + 1; /* i is index of most significant non-zero digit */
    /* if everything zero, ensure a single zero digit */
    if (biout->numdigits == 0) {
        biout->numdigits = 1;
        biout->digits[0] = '0';
    }
}
