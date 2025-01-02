// Implement stack as  linked list

#include "string.h"

#include "stack.h"

/* Single node */
struct node {
    int data;
    struct node *next;
};

/* First node; initially points to nothing */
static struct node *top = NULL;

void make_empty(void){


    while(!is_empty()){
        pop();
    }

}

bool is_empty(void){

    return top == NULL;

}

bool is_full(void){

    return false;

}

void push(int i){

    struct node *new_top;

    if(is_full()){
        terinate("Error in push: stack is full");
    }

    new_top->data = i;
    new_top->next = top;
    top = new_top;
}

int pop(void){

    struct node *old_top;
    int i;

    if(is_empty()){
        terminate("Error in pop: stack is empty");
    }

    old_top = top;
    i = old_top->data;
    top = old_top->next;
    free(old_top);
    return i;

}