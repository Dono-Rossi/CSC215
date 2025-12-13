#include <stdio.h>

/* reverse_ptr) */
reverse_ptr(s)
char *s;
{
    char *i, *j, tmp;
    i = s;
    j = s;
    while (*j)          /* move j to terminating '\0' */
        j++;
    if (j != s)         /* step back from '\0' */
        j--;
    while (i < j) {
        tmp = *i;
        *i = *j;
        *j = tmp;
        i++;
        j--;
    }
}

/* atoi_ptr */
int atoi_ptr(s)
char *s;
{
    int n;
    int sign;

    n = 0;
    sign = 1;

    /* skip leading whitespace */
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

/* itoa_ptr */
itoa_ptr(n, s)
int n;
char *s;
{
    int sign;
    char *p;

    sign = n;
    p = s;

    if (n < 0)
        n = -n; /* K&R behavior; does not handle INT_MIN specially */

    /* generate digits in reverse order */
    do {
        *p++ = (n % 10) + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        *p++ = '-';

    *p = '\0';
    reverse_ptr(s);
}

/* strcat_ptr */
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

/* Demo */
int main()
{
    char buf[100];
    char small[40];
    int v;

    printf("Demo of pointer-based functions\n\n");

    v = atoi_ptr("  +12345");
    printf("atoi_ptr(\"  +12345\") = %d\n", v);
    v = atoi_ptr(" -6789xyz");
    printf("atoi_ptr(\" -6789xyz\") = %d\n\n", v);

    itoa_ptr(4321, buf);
    printf("itoa_ptr(4321) -> \"%s\"\n", buf);
    itoa_ptr(-900, buf);
    printf("itoa_ptr(-900) -> \"%s\"\n\n", buf);

    small[0] = '\0';
    strcat_ptr(small, "stressed");
    printf("before reverse: \"%s\"\n", small);
    reverse_ptr(small);
    printf("after  reverse: \"%s\"\n\n", small);

    buf[0] = '\0';
    strcat_ptr(buf, "Hello");
    strcat_ptr(buf, ", ");
    strcat_ptr(buf, "pointer strcat!");
    printf("strcat_ptr result: \"%s\"\n", buf);

    return 0;
}
