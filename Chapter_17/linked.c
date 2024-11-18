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
void *add_to_front(int data){

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
void *add_to_end(int data){

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
int remove_by_value(int data){

    struct node *current = head;
    struct node *last = head;

    while(current->next != NULL){

        if(current->value == data){

            last->next = current->next;
            free(current);

            return 0;

        }

    }

    return 1;

}

/* Print content of list */
void print_list(void){

    int count = 0;
    struct node *current = head;
    printf("\n");
    printf("LIST CONTENTS\n");
    while(current->next != NULL){

        printf("Item %d is: %d\n", count, current -> value);

    }



}

/* Print options for user */
void print_options(){

    printf("0: Add to front of list\n");
    printf("1: Add to end of list\n");
    printf("2: Remove by value\n");
    printf("3: Print contents of list\n");
    printf("4: Exit\n");

}

int main(void){

    int option;
    int data;
    int outcome;

    for(;;){

        printf("Welcome to your linked list hell!\n");
        print_options();
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option){

            case 0:
                // Add to front
                printf("Enter value you would like to add to front: ");
                scanf("%d", &data);
                add_to_front(data);

                break;

            case 1:
                // Add to end
                printf("Enter value you would like to add to end: ");
                scanf("%d", &data);
                add_to_end(data);

                break;
            
            case 2:
                // Remove by value
                printf("Enter value you would like to remove: ");
                scanf("%d", &data);
                outcome = remove_by_value(data);

                if(outcome == 1){
                    printf("Failed to find requested value! Nothing was removed");
                }


                break;

            case 3:
                //Print contents
                print_list();

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