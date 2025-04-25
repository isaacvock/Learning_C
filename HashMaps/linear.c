#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define STR_LEN 50

typedef struct{
    char key[STR_LEN];
    int value;
} item;


item* linear_search(item* items, size_t size, const char* key);

int main(void){

    item items[] = {
        {"foo", 10}, {"bar", 42}, {"bazz", 36}, {"buzz", 7},
        {"bob", 11}, {"jane", 100}, {"x", 200}
    };

    size_t num_items = sizeof(items) / sizeof(item);

    item* found = linear_search(items, num_items, "bob");

    if (!found){
        return 1;
    }
    printf("Value for 'bob' is %d\n", found->value);

    return 0;

}


item* linear_search(item* items, size_t size, const char* key){


    for(size_t i = 0; i<size; i++){

        if(strcmp(items[i].key, key) == 0){

            return &items[i];

        }

    }


    return NULL;


}