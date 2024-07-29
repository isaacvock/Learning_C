#include <stdio.h>

int main(void){

    /* Reading/Writing different int types */
    unsigned int u;

    printf("Give me an unsigned int: ");
    scanf("%u", &u);
    printf("%u\n", u);

    printf("Give me another unsigned int: ");
    scanf("%o", &u);
    printf("%o\n", u);

    printf("Give me another unsigned int: ");
    scanf("%x", &u);
    printf("%x\n", u);

    short s;

    printf("Give me a short int: ");
    scanf("%hd", &s);
    printf("%hd\n", s);


    long l;
    printf("Give me a long int: ");
    scanf("%ld", &l);
    printf("%ld\n", l);



    long long ll;

    printf("Give me a long long int: ");
    scanf("%lld", &ll);
    printf("%lld\n", ll);

    return(0);
}