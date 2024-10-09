#include "stack.h"
#include <stdbool.h>

int contents[100];
int top = 0;



void make_empty(void){

    for(int c = 0; c<100; c++){

        contents[c] = -1;

    }

    top = 0;

}

int is_empty(void){

    int isempty;
    if(top == 0){
        isempty = 1;
    }else{
        isempty = 0;
    }

    return isempty;

}

int is_full(void){

    int isfull;
    if(top == 100){
        isfull = 1;
    }else{
        isfull = 0;
    }

    return isfull;

}

void push(int i){

    contents[top] = 1;
    top++;

}

int pop(void){

    return contents[top--];
    
}