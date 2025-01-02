// Implementing a stack using arrays

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

static int contents[STACK_SIZE];
static int current_size = 0;

static void terminate(const char *message){
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(void){

    current_size = 0;

}


bool is_empty(void){

    return current_size == 0;

}


bool is_full(void){

    return current_size == STACK_SIZE;

}

void push(int i){

    if(is_full()){
        terminate("Error in push: stack is full");
    }

    current_size++;
    contents[current_size] = i;

}

int pop(void){

    if(is_empty()){
        terminate("Error in pop: stack is empty");
    }
    
    current_size--;
    return contents[current_size + 1];

}