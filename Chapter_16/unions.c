#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Better mixed data structures */
typedef struct {
    bool is_int;
    union{
        int i;
        double d;
    } u;
} Number2;

void print_element(Number2 arr[], int i);

int main(void){



    Number2 number2_array[1000];
    number2_array[0].u.i = 1;
    number2_array[0].is_int = true;

    number2_array[1].u.d = 3.14;
    number2_array[1].is_int = false;

    print_element(number2_array, 1);
    

    /* Mixed data structures with unions */
    typedef union {
        int i;
        double d;
    } Number;

    Number number_array[1000];
    number_array[0].i = 5;
    number_array[1].d = 8.395;

    printf("Element 0 is %d\n", number_array[0].i);
    printf("Element 1 is %f\n", number_array[1].d);


    /* Declaring and initializing unions */
    union{
        int i;
        double d;
    } u;

    u.i = 82;
    printf("element i is %d\n", u.i); 

    union{
        int i;
        double d;
    } u2 = {0};


    union{
        int i;
        double d;
    } u3 = {.d = 10.0};

}

void print_element(Number2 arr[], int i){

    if(arr[i].is_int){
        printf("Element %d is %d\n", i, arr[i].u.i);
    }else{
        printf("Element %d is %f\n", i, arr[i].u.d);
    }

}