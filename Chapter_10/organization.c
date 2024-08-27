#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SECRET 100


int main(void){

    int secret; 
    int guess = 0;
    char play = 'y';
    int count;

    /* Implement a guessing game */
    printf("Guess the secret number between 1 and 100.\n\n");


    srand((unsigned) time(NULL)); /* Initialize RNG */

    while(play == 'y' | play == 'Y'){

        count = 0;
        secret = ( rand() % MAX_SECRET ) + 1;

        printf("A new number has been chosen.\n");

        while(guess != secret){

            count++;

            printf("Enter guess: ");
            scanf("%d", &guess);

            if(guess < secret){
                printf("Too low; try again\n");
            }else if(guess > secret){
                printf("Too high, try again\n");
            }

        }

        printf("You won in %d guess(es)!\n", count);
        printf("Play again? (Y/N) ");
        scanf(" %c", &play);


    }




}