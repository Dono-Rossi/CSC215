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
    char maxdigits, i, carry, digit1, digit2, sum;
    char leading_zeros;
    
    maxdigits = (bi1->numdigits > bi2->numdigits) ? bi1->numdigits : bi2->numdigits;
    biout->digits = alloc(maxdigits + 1);
    biout->negative = 0;
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
    
    leading_zeros = 0;
    for (i = biout->numdigits - 1; i > 0; i--) {
        if (biout->digits[i] == '0') {
            leading_zeros++;
        } else {
            break;
        }
    }
    biout->numdigits -= leading_zeros;
}
