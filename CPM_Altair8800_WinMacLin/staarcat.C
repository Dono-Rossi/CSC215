
#include <stdio.h>

char *strcat_ptr(s, t)
char *s;
char *t;
{
    char *p;

    p = s;
    while (*p)
        p++;

    while ((*p++ = *t++) != '\0')
        ;
    return s;
}

int main()
{
    char buffer[100];

    printf("starcat starting...\n"); /* makes it obvious the program ran */

    /* Test pointer version (K&R-style definition above) */
    buffer[0] = '\0';
    strcat_ptr(buffer, "Hello");
    strcat_ptr(buffer, ", ");
    strcat_ptr(buffer, "pointer version!");
    printf("Pointer version result: %s\n", buffer);

    return 0;
}
