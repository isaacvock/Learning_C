#include <stdio.h>

int main(void){

    /* Determine the length of a message */
    int count = 0;
    char ch2;

    printf("Enter a message: ");
    ch2 = getchar();
    while(ch2 != '\n'){
        count++;
        ch2 = getchar();
    }
    printf("Your message was %d character(s) long.\n", count);


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


    /* Character types */

    char ch;
    int i;

    printf("i is: %d\n", i);
    printf("ch is: %c\n", ch);

    i = 'a';
    printf("i is now: %d\n", i);
    ch = 65;
    printf("ch is now: %c\n", ch);
    ch = ch + 1;
    printf("ch is now: %c\n", ch);
    ch++;
    printf("ch is now: %c\n", ch);


    return(0);
}