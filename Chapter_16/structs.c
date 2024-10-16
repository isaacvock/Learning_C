#include <stdio.h>
#include <string.h>

#define NAME_LEN 30

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