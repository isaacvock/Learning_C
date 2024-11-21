// It's turtles all the way down
// Pointers to Pointers

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

struct node {
    int value;
    struct node *next;
};

void add_to_list(struct node **list, int n);

int main(void){
    
    /* Manually create linked list for testing */
    struct node *head;
    struct node *second;
    struct node *third;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head->value = 1;
    head->next = second;

    second->value = 2;
    second->next = third;

    third->value = 3;
    third->next = NULL;

    add_to_list(&head, 0);

    /* Print contents of list */
    int count = 1;
    for(struct node *curr = head; curr != NULL; curr=curr->next){
        printf("Element %d is %d\n", count, curr->value);
        count++;
    }

}

void add_to_list(struct node **list, int n){

    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = *list;
    *list = new_node;

}