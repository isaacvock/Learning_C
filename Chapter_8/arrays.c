#include <stdio.h>
#define N 10

int main(void){

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