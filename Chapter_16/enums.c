#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};

int main(void){

    enum suit s1, s2;

    s1 = DIAMONDS;

    printf("s1 is %d\n", s1);

}