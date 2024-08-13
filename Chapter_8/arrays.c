#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void){

    /* Dealing a hand of cards */
    int handsize;
    int rand_rank;
    int rand_suit;

    srand(time(NULL));


    const char rank_code[] = {'2', '3', '4', '5', '6', 
                              '7', '8', '9', 't', 'j',
                              'q', 'k', 'a'};
    const char suit_code[] = {'c', 'd', 'h', 's'};

    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};


    printf("Enter number of cards in hand: ");
    scanf("%d", &handsize);


    printf("Your hand: ");
    for(int h = 0; h < handsize; h++){

        int new_card = 0;
        while(new_card == 0){

            rand_rank = rand() % NUM_RANKS;
            rand_suit = rand() % NUM_SUITS;

            if(!(in_hand[rand_suit][rand_rank])){
                in_hand[rand_suit][rand_rank] = true;
                new_card = 1;
                printf("%c%c ", rank_code[rand_rank], suit_code[rand_suit]);
            }


        }

    }
    printf("\n");



    /* Multi-dimensional arrays */

    int m[2][4] = {{1, 1, 1, 2},
                   {3, 3, 4, 4}};

    double ident[N][N];

    for(int x = 0; x < N; x++){

        for(int y = 0; y < N; y++){

            if(y == x){
                ident[x][y] = 1;
            }else{
                ident[x][y] = 0;
            }

        }

    }

    /* Check number of repeated digits */
    int number;
    int digit;
    bool digit_seen[10] = {false}; /* 10 possible values for each digit */
    printf("Enter a number: ");
    scanf("%d", &number);

    while (number > 0){

        digit = number % 10;
        number = number / 10; /* Casting to int will throw out decimal */
        
        if(digit_seen[digit] == false){

            digit_seen[digit] = true;

        }else{

            printf("Repeated digit\n");
            break;

        }

    }




    /* Initialization of arrays */
    int d[5] = {1, 2, 3, 4, 5};

    /* Reverse a series of numbers*/

    int c[10];
    printf("Enter 10 numbers: ");

    for(int j = 0; j < 10; j++){
        scanf("%d", &c[j]);
    }

    printf("In reverse order: ");
    for(int k = 9; k >= 0; k--){
        printf("%d ", c[k]);
    }
    printf("\n");


    /* Declare an array */

    int a[10];
    int b[N];

    /* Indexing an array */
    a[0] = 1;
    printf("%d\n", a[5]);
    printf("%d\n", a[0]);

    /* Loops and arrays*/
    for(int i = 0; i < N; i++){
        b[i] = i * 2;
        printf("Enter index %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("%d\n", b[5]);
    printf("%d\n", b[0]);
    printf("%d\n", a[1]);


}