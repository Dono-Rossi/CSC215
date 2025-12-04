CHeck inputs for ints, then atoi it. Read inputs, check if an int, if not return something, then add together the inputs and return.
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
	int sum = 0;
	int i;
	int num;
	printf("Enter numbers")
	if (scanf("%d", &num) == 1 {
		for (i = 1; i < argc; i++) {
			sum += atoi(argv[i]);
	}
	} else { 
		print("enter only integers")
	}
	printf(sum);
	return 0;
}
