#include <stdio.h>

reverse_ptr(s)
char *s;
{
    char *i, *j, tmp;
    i = s;
    j = s;
    while (*j)          /* move j to end */
        j++;
    if (j != s) j--;    /* step back from terminating '\0' */
    while (i < j) {
        tmp = *i;
        *i = *j;
        *j = tmp;
        i++;
        j--;
    }
}

/* atoi_ptr: convert string s to integer (pointer style) */
int atoi_ptr(s)
char *s;
{
    int n = 0;
    int sign = 1;

    /* skip whitespace */
    while (*s == ' ' || *s == '\t' || *s == '\n')
        s++;

    if (*s == '-') {
        sign = -1;
        s++;
    } else if (*s == '+') {
        s++;
    }

    while (*s >= '0' && *s <= '9') {
        n = 10 * n + (*s - '0');
        s++;
    }
    return sign * n;
}

/* itoa_ptr: convert integer n to string s (pointer style).
 * Writes digits into s (including terminating '\0').
 * Uses reverse_ptr to fix digit order.
 */
itoa_ptr(n, s)
int n;
char *s;
{
    int sign;
    char *p;

    p = s;
    sign = n;
    if (n < 0)
        n = -n; /* note: undefined for INT_MIN on two's-complement, simple K&R behavior */

    /* generate digits in reverse order */
    do {
        *p++ = (n % 10) + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        *p++ = '-';

    *p = '\0';
    reverse_ptr(s);
}

/* strcat_ptr: concatenate t to end of s (pointer style) */
char *strcat_ptr(s, t)
char *s;
char *t;
{
    char *p;
    p = s;
    while (*p)      /* find end of s */
        p++;
    while ((*p++ = *t++) != '\0') /* copy t including '\0' */
        ;
    return s;
}

/* Demo main */
int main()
{
    char buf[100];
    char small[40];
    int v;

    printf("Demo of pointer-based string/number functions\n\n");

    /* atoi_ptr usage */
    v = atoi_ptr("  +12345");
    printf("atoi_ptr(\"  +12345\") = %d\n", v);
    v = atoi_ptr(" -6789xyz");
    printf("atoi_ptr(\" -6789xyz\") = %d\n\n", v);

    /* itoa_ptr usage */
    itoa_ptr(4321, buf);
    printf("itoa_ptr(4321) -> \"%s\"\n", buf);
    itoa_ptr(-900, buf);
    printf("itoa_ptr(-900) -> \"%s\"\n\n", buf);

    /* reverse_ptr usage */
    /* small must be a writable array (not a string literal) */
    /* initialize small using strcat_ptr so we don't rely on other library calls */
    small[0] = '\0';
    strcat_ptr(small, "stressed");
    printf("before reverse: \"%s\"\n", small);
    reverse_ptr(small);
    printf("after  reverse: \"%s\"\n\n", small);

    /* strcat_ptr */
    buf[0] = '\0';
    strcat_ptr(buf, "Hola");
    strcat_ptr(buf, ", ");
    strcat_ptr(buf, "pointer strcat!");
    printf("strcat_ptr result: \"%s\"\n", buf);

    return 0;
}
