#include <stdio.h>
#include <string.h>

#define MAX_PART_NAME 60
#define MAX_PART_COUNT 100

struct part{
    int ID;
    char name[MAX_PART_NAME + 1];
    int quantity;
};


struct part database[MAX_PART_COUNT];
int current_quantity = 0;

void add_part(void);
void print_part(void);
void update_quantity(void);
void print_inventory(void);
void print_part_struct(struct part part);

int main(void){

    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while(getchar() != '\n'){
            ;
        }
        switch(code) {
            case 'i': add_part();
                      break;
            case 's': print_part();
                      break;
            case 'u': update_quantity();
                      break;
            case 'p': print_inventory();
                      break;
        }
    }

}


/*
ADD PART TO DATABASE
*/
void add_part(void){

    int part_number;
    char *part_name;
    int init_quantity;

    if (current_quantity == MAX_PART_COUNT){
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);


    /* Check to make sure part name is not already in list */
    for(int i = 0; i < current_quantity; i++){

        if(strcmp(part_name, database[i].name) == 0){

            printf("!!Error: part already exists!!");
            return;

        }

    }

    /* Add part */
    database[current_quantity++] = (struct part) {
        .ID = part_number,
        .name = part_name,
        .quantity = init_quantity
    };



}

/*
PRINT NAME OF PART
*/
void print_part(void){

    char *part_name;

    /* Look for part */
    for(int i = 0; i < current_quantity; i++){

        if(strcmp(part_name, database[i].name) == 0){

            print_part_struct(database[i]);

            break;

        }

    }

    printf("!!Error: part does not exist in database!!");

}


/*
CHANGE QUANTITY OF A PART
*/
void update_quantity(void){

    char *part_name;
    int new_quantity;

    /* Look for part */
    for(int i = 0; i < current_quantity; i++){

        if(strcmp(part_name, database[i].name) == 0){

            database[i].quantity = new_quantity;

            break;

        }

    }

    printf("!!Error: part does not exist in database!!");
 


}


/*
PRINT ENTIRE DATABASE
*/
void print_inventory(void){

    for(int i = 0; i++; i < current_quantity){

        print("ENTRY %d\n:", i+1);
        print_part_struct(database[i]);
        printf("\n");

    }


}


/*
Print a given part struct
*/
void print_part_struct(struct part part){

    printf("Part ID is: %d\n", part.ID);
    printf("Part name is: %s\n", part.name);
    printf("Part quantity is: %d\n", part.quantity);

}
