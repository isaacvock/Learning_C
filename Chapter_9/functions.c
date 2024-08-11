#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


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

/* Function to average 2 numbers */
double average(double a, double b){
    return (a + b) / 2;
}

int main(void){

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

