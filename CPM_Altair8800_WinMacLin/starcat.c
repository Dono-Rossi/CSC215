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

/* Demonstration main */
int main()
{
    char buffer[100];


    buffer[0] = '\0';
    strcat_ptr(buffer, "Hello");
    strcat_ptr(buffer, ", ");
    strcat_ptr(buffer, "pointer version!");
    printf("Pointer version result: %s\n", buffer);

    return 0;
}
