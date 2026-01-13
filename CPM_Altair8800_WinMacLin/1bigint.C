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
if (bi1->negative == 0 && bi2->negative == 0) {
        add_abs(bi1, bi2, biout);
        biout->negative = 0;
        return;
    } else if (bi1->negative == 1 && bi2->negative == 1) {
        add_abs(bi1, bi2, biout);
        biout->negative = 1;
        return;
    } else if (bi1->negative == 0 && bi2->negative == 1) {
        /* bi1 + (-bi2) => bi1 - bi2 */
        sub_bigints(bi1, bi2, biout);
        return;
    } else { /* bi1 negative, bi2 positive: (-bi1) + bi2 => bi2 - bi1 */
        sub_bigints(bi2, bi1, biout);
        return;
    }
}

void sub_bigint(bi1, bi2, biout)
struct bigint *bi1;
struct bigint *bi2;
struct bigint *biout;
{
    char s1 = bi1->negative;
    char s2 = bi2->negative;
    char cmp;

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
