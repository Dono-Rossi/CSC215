#include <stdio.h>

main() {
    int biggest;
    unsigned ubiggest;
    unsigned n, m, prod;
    biggest = 32767;
    ubiggest = 65535;
    printf("The value of biggest is now %d.\n", biggest);
    printf("The value of ubiggest is now %u.\n", ubiggest);
    biggest++;
    ubiggest++;
    printf("Add 1 to it and we get %u!\n", biggest);
    printf("Add 1 to it and we get %d!\n", ubiggest);
    biggest += 100
    ubiggest += 100
    printf("Add one hunred and be get %u!\n", biggest);
    printf("Add one hundred to u and we get %u!\n", ubiggest);
    biggest--;
    ubiggest--;
    printf("Lez try something else, subtracting one and getting %u!\n", biggest);
    printf("Now subtract one or sumting from u and we get %u!\n", ubiggest);
    n =  65000;
    m = 3;
    prod = n * m;
    printf("%u * %u = %u -- Why?\n", m, n, prod);
}
