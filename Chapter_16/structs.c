#include <stdio.h>
#include <string.h>

#define NAME_LEN 30
#define FIRST_NAME_LEN 30
#define LAST_NAME_LEN 30

/* Nested structs */
struct person_name {
    char first[FIRST_NAME_LEN+1];
    char middle_intitial;
    char last[LAST_NAME_LEN+1];
};

struct student {
    struct person_name name;
    int id, age;
    char sex;
};

/* Basic b structs */
struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

typedef struct {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
} Part;

void print_part(struct part p);
struct part build_part(int number, const char *name, int on_hand);

int main(void){

    /* Arrays of structs*/
    struct part inventory[100];
    inventory[0] = (struct part) {10, "bean", 1};
    strcpy(inventory[1].name, "izzy");
    inventory[1].number = 2;
    inventory[1].on_hand = 1;
    printf("ELEMENT 0: \n");
    print_part(inventory[0]);
    printf("ELEMENT 1: \n");
    print_part(inventory[1]);
    printf("Part's name is %s\n", inventory[0].name);
    strcpy(inventory[0].name, "spoot");
    printf("Part's name is now %s\n", inventory[0].name);

    struct part inventory_i[100] = 
        {[0].number = 528, [0].on_hand = 10, [0].name[0] = '\0'};
    printf("ELEMENT 0 OF inventory_i: \n");
    print_part(inventory_i[0]);

    /* Nested structs */
    struct student student1, student2;
    struct person_name me = {"Isaac", 'W', "Vock"};
    strcpy(student1.name.first, "Fred");
    student2.name = me;

    printf("student1's first name is %s\n", student1.name.first);
    printf("student2's first name is %s\n", student2.name.first);

    /* Compound literals and structs */
    print_part((struct part) {528, "Disk drive", 10});

    /* Messing around */
    struct {
        int number;
        char name[NAME_LEN+1];
        int on_hand;
    } part1 = {528, "Disk drive", 10},
      part2 = {.on_hand = 914, .name = "Printer cable", .number = 5};

    struct part part3 = {111, "Beans", 1};
    Part part4 = {100, "Spoots", 1};

    printf("Part number %d\n", part1.number);
    printf("Part name: %s\n", part1.name);
    printf("Quantity on hand: %d\n", part1.on_hand);

    printf("Part number %d is %s\n", part3.number, part3.name);
    printf("Part number %d is %s\n", part4.number, part4.name);

    print_part(part3);

    struct part part5 = build_part(101, "Garbanzo", 300);

    print_part(part5);

}

void print_part(struct part p){
    printf("Part number: %d\n", p.number);
    printf("Part name: %s\n", p.name);
    printf("Quantity on hand: %d\n", p.on_hand);
}

struct part build_part(int number, const char *name,
                        int on_hand){

    struct part p;

    p.number = number;
    strcpy(p.name, name);
    p.on_hand = on_hand;
    return p;

}