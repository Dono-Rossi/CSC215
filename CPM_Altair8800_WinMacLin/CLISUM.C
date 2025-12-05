#include <stdio.h>

atoi(s)
char s[];
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + s[i] - '0';
	return(n);
}

main(argc, argv)
int argc;
char **argv;
{
	int sum;
	sum = 0;
	int i;
	int j;
	for (i = 1; i < argc; i++) {
		for(j = 0; argv[i][j] != '\0'; j++){
			if (argv[i][j] < '0' || argv[i][j] > '9'){
				printf("Error, %s is not a number", argv[i]); 
				return -1; 
			}
		}
	sum += atoi(argv[i]);
	
}
	printf("%d", sum);
	return 0;
}
