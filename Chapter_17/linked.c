/* Implementing a linked list */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Single node */
struct node {
    int value;
    struct node *next;
};

/* First node; initially points to nothing */
struct node *head = NULL;

/* Add node to front of list */
struct node *add_to_front(int data){

    struct node *new = malloc(sizeof(struct node));

    if(new == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    new -> value = data;

    if(head == NULL){
        head = new;
        new -> next = NULL;
    }else{
        new -> next = head;
        head = new;
    }

}

/* Add node to end of list */
struct node *add_to_end(int data){

    struct node *new = malloc(sizeof(struct node));

    if(new == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    new -> value = data;

    if(head == NULL){
        head = new;
        new -> next = NULL;
    }else{

        // Traverse to end of list
        struct node *current = head;
        for(;;){
            if(current->next == NULL){
                break;
            }else{
                current = current->next;
            }
        }

        current->next = new;
        new->next = NULL;
    }

}

/* Remove node by value */
void remove_by_value(int data){

    struct node *current = head;
    struct node *last = head;

    while(current->next != NULL){

        if(current->value == data){

            last->next = current->next;
            free(current);

        }

    }

}

/* Print content of list */
void print_list(){



}

/* Print options for user */
void print_options(){

    printf("0: Add to front of list\n");
    printf("1: Add to end of list\n");
    printf("2: Remove by value\n");
    printf("3: Print contents of list\n");
    printf("4: Exit\n")

}

int main(void){

    int option;
    int data;

    for(;;){

        printf("Welcome to your linked list hell!\n");
        print_options();
        printf("Enter option: \n");
        scanf("%d", &option);

        switch(option){

            case 0:
                // Add to front
                printf("What value would you like to add to front?\n");
                scanf("%d", &data);
                add_to_front(data)

                break;

            case 1:
                // Add to end

                break;
            
            case 2:
                // Remove by value

                break;

            case 3:
                //Print contents

                break;

            case 4:
                //Exit

                break;

        }

        if(option == 4){
            // Get out of loop
            break;
        }


    }


}