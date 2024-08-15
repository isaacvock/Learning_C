#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10

/* Function declaration*/
double average(double a, double b);

/* Quicksort declaration */
void quicksort(int a[], int low, int high);

int reorder(int a[], int low, int high);

/* Easy way to deal with multi-dim arrays as input */
int sum_2d_array(int r, int c, int a[r][c]){

    int i, j, sum = 0;

    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){

            sum += a[i][j];

        }
    }

    return sum;

}

/* Function to sum elements in an array */
int sum_array(int a[], int n){

    int i, sum = 0;

    for(i = 0; i < n; i++){
        sum += a[i];
    }

    return sum;

}


/* Check if a number is prime */
bool check_prime(int n){

    if(n == 1){
        return false;
    }else if(n == 2){
        return true;
    }else{

        int max_check = sqrt(n);

        for(int i = 2; i <= max_check; i++){

            if(n % i == 0){
                return false;
            }

        }

        return true;

    }


}

/* Print a countdown */
void print_count(int n){
    printf("T minus %d and counting\n", n);
}


int main(void){

    /* Show off my Quicksort implementation*/
    printf("Enter 10 numbers to be sorted: ");
    int Q[N], i;
    for(i = 0; i < N; i++){
        scanf("%d", &Q[i]);
    }

    quicksort(Q, 0, N-1);

    printf("In sorted order: ");
    for(i = 0; i < N; i ++){
        printf("%d", Q[i]);
    }
    printf("\n");
    

    /* Showing off compound literals */
    int total3;
    total3 = sum_array((int []){3, 0, 3, 4, 1}, 5);

    printf("On the fly total is %d\n", total3);

    /* Show off 2d array sum */
    int M[10][15], total2d;

    for(int k = 0; k < 10; k++){
        for(int l = 0; l < 15; l++){

            M[k][l] = k + l;

        }
    }

    total2d = sum_2d_array(10, 15, M);
    printf("Your 2D array total is %d\n", total2d);

    /* Show off sum_array */
    int b[100], total;

    for(int j = 0; j < 100; j++){

        b[j] = j;

    }

    total = sum_array(b, 100); /* will be 0 */

    printf("Your total is %d\n", total);

    /* Test if number is prime */
    int maybe_prime;
    bool prime_check;
    
    printf("Enter a number: ");
    scanf("%d", &maybe_prime);

    prime_check = check_prime(maybe_prime);

    if(prime_check){
        printf("Prime\n");
    }else{
        printf("Not prime\n");
    }




    /* Print a countdown */
    for(int i = 10; i > 0; i--){
        
        print_count(i);

    }

    /* Average pairs of numbers */
    double x, y, z;

    printf("Enter three numbers: ");
    scanf("%lf %lf %lf", &x, &y, &z);

    printf("Average of %g and %g: %g\n", x, y, average(x, y));
    printf("Average of %g and %g: %g\n", y, z, average(y, z));
    printf("Average of %g and %g: %g\n", x, z, average(x, z));

    return 0;

}

/* Function to average 2 numbers */
double average(double a, double b){
    return (a + b) / 2;
}

void quicksort(int a[], int low, int high){

    if(low == high){

        return;

    }else{

        int pivotlocale = reorder(a, low, high);
        quicksort(a, low, pivotlocale-1);
        quicksort(a, high, pivotlocale+1);

    }



}

int reorder(int a[], int low, int high){


    int pivotpoint = a[low];
    bool empty_high = false;
    bool empty_low = true;

    while(low != high){

        while(empty_low & low != high){

            if(a[high] < pivotpoint){

                a[low] = a[high];
                empty_high = true;
                empty_low = false;

            }else{

                high -= 1;

            }

        }

        while(empty_high & low != high){

            if(a[low] >= pivotpoint){

                a[high] = a[low];
                empty_high = false;
                empty_low = true;

            }else{

                low += 1;

            }


        }

        a[low] = pivotpoint;


    }

}