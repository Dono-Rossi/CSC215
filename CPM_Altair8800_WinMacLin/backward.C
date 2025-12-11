#include <stdio.h>

main(argc, argv)
char *argv[];
{
    FILE *fp;
    char linbuf[128];
    char line;
    int charnum;
    int i;
    if (argc != 2) {
        printf("Usage: pnum filename <cr>\n");
        exit();
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Can’t open %s\n", argv[1]);
        exit();
    }
    charnum = 0;
    while (fgets(linbuf, 128, fp)){
        for (i = 0; linbuf[i] != '\0' && linbuf[i] != '\n'; i++) {
            charnum++;
        }
        for (i = 0; i < (charnum/2); i++) {
            line = linbuf[i];
            linbuf[i] = linbuf[charnum - i - 1];
            linbuf[charnum - i - 1] = line;
        }
        printf("%s", linbuf);
        charnum = 0;
    }
    fclose(fp);
}
