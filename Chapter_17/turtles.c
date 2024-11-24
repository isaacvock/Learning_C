// It's turtles all the way down
// Pointers to Pointers and Functions

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

struct node {
    int value;
    struct node *next;
};

/* Alt string storage strategy with flexible array */
struct vstring {
    int len;
    char chars[];
};

/* Add element to linked list without global variable BS */
void add_to_list(struct node **list, int n);

/* Print values of function f */
void tabulate(double (*f) (double), double first,
              double last, double incr);

int main(void){
    
    /* FLEXIBLE ARRAY MEMBERS */

    struct vstring *str = malloc(sizeof(struct vstring) + 10);
    str->len = 10;

    /* POINTERS TO FUNCTIONS */

    /* Report values of trigonometric functions */
    double final, increment, initial;
    printf("Enter initial value: ");
    scanf("%lf", &initial);

    printf("Enter final value: ");
    scanf("%lf", &final);

    printf("Enter increment size: ");
    scanf("%lf", &increment);

    printf("\n      x       cos(x)"
           "\n  ---------  --------\n");
    tabulate(cos, initial, final, increment);

    printf("\n      x       sin(x)"
           "\n  ---------  --------\n");
    tabulate(sin, initial, final, increment);

    printf("\n      x       tan(x)"
           "\n  ---------  --------\n");
    tabulate(tan, initial, final, increment);


    /* POINTERS TO POINTERS */

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

void tabulate(double (*f) (double), double first,
              double last, double incr){

    double value;

    for(double i = first; i <= last; i = i + incr){

        value = f(i);
        printf("\n  %lf %lf \n", i, value);

    }

}
