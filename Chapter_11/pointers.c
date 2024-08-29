#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Prototypes */
void decompose(double x, long *int_part, double *frac_part);

void max_min(int a[], int n, int *max, int *min);

int main(void){

    /* FIND LARGEST AND SMALLEST ELEMENTS IN ARRAY */
    int M[10];


    printf("Enter 10 numbers: ");
    for(int k = 0; k < 10; k++){
        scanf("%d", &M[k]);
    }

    printf("You provided: ");
    for(int m = 0; m < 10; m++){
        printf("%d ", M[m]);
    }
    printf("\n");

    int big;
    int small;

    max_min(M, 10, &big, &small);

    printf("The largest value in the array is: %d\n", big);
    printf("The smallest value in the array is: %d\n", small);

    /* BASIC MESSING AROUND */

    int *p; /* p can point to an int */
    double *q;
    char *r;

    int i = 2;
    p = &i;

    printf("%d\n", *p); /* `*p` accesses value of at p */

    long I;
    double D;
    decompose(3.141592, &I, &D);

    printf("int part is %ld\n", I);
    printf("decimal part is %f\n", D);

}

/* Passing pointers as function args */
void decompose(double x, long *int_part, double *frac_part){
    *int_part = (long) x;
    *frac_part = x - *int_part;
}

/* Find min and max of an array */
void max_min(int a[], int n, int *max, int *min){

    for(int i = 0; i<n; i++){

        if(i == 0){
            *max = a[i];
            *min = *max;
        }else{

            if(a[i] > *max){
                *max = a[i];
            }else if(a[i] < *min){
                *min = a[i];
            }

        }

    }

}