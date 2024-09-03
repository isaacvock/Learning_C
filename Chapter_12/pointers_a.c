#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void){


    /* Pointers and multi-dimensional arrays */
    int X[10][15];
    int *w = &X[0][0];

    while(w <= &X[10][15]){

        *w++ = 0;

    }

    for(int y = 0; y < 10; y++){
        for(int z = 0; z < 15; z++){

            printf("Row %d column %d is: %d\n", y, z, X[y][z]);

        }
    }

    int *w2;
    for(w2 = X[3]; w2 < X[3] + 15; w2++){

        *w2 = 1;

    }


    for(int y = 0; y < 10; y++){
        for(int z = 0; z < 15; z++){

            printf("Row %d column %d is: %d\n", y, z, X[y][z]);

        }
    }

    /* Reverse a series of numbers */
    int c[10];
    int *r = &c[0];
    printf("Enter 10 numbers: ");

    while(r < c + 10){
        scanf("%d", r++);
    }

    r--;

    printf("In reverse order: ");
    while(r >= c){
        printf("%d ", *r--);
    }

    printf("\n");


    /* Cute array name as pointer trick */
    int b[10];

    for(int n = 0; n < 10; n++){
        *(b+n) = n;
    }

    for(int m = 0; m<10; m++){

        printf("Element %d is: %d\n", m, b[m]);

    }



    /* Populate array with pointer arithmetic */
    int a[10], *p;

    p = &a[0];

    for(int i=0; i<10; i++){

        *p = i;
        p++;

    }

    for(int j = 0; j<10; j++){

        printf("Element %d is: %d\n", j, a[j]);

    }


    /* Sum array with pointer arithmetic */

    int *q;
    int sum = 0;

    for(q = &a[0]; q < &a[10]; q++){

        sum += *q;

    }

    printf("Sum of elements is %d\n", sum);

}