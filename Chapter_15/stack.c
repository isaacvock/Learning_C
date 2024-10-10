#include "stack.h"
#include <stdbool.h>

int contents[100];
int top = 0;



void make_empty(void){

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

    if(top == 100){
        printf("Stack overflow!");
    }else{
        contents[top] = i;
        top++;
    }



}

int pop(void){

    if(top == 0){

        print("Nothing to pop!\n");
        return -1;

    }else{

        return contents[top--];

    }

    
}