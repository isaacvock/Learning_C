#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>>
#include "hash.h"

// hash table entry
typedef struct {
    const char* key;
    void* value;
} ht_entry;

// full on hash table
struct ht {
    ht_entry* entries; // hash slots
    size_t capacity; // size of _entries array
    size_t length; // number of items in hash table
};

void exit_nomem(void) {
    fprintf(stderr, "out of memory\n");
    exit(1);
}

int main(void){

    ht* counts = ht_create();
    if (counts == NULL){
        exit_nomem();
    }

    // Read next word from stdin (at most 100 chars)
    char word[101];
    while(scanf("%100s", word) != EOF){
        // Look up word.
        void* value = ht_get(counts, word);
        if(value != NULL){
            //Already exists, increment int that value points to.
            int* pcount = (int*)value;
            (*pcount)++;
            continue;
        }

        // WOrd not found, allocate space for new int and set to 1
        int* pcount = malloc(sizeof(int));
        if(pcount == NULL){
            exit_nomem();
        }
        *pcount = 1;
        if(ht_set(counts, word, pcount) == NULL){
            exit_nomem();
        }
    }

    // Print out words and frequencies, freeing values as we go.
    hti it = ht_iterator(counts);
    while(ht_next(&it)){
        printf("%s %d\n", it.key, *(int*)it.value)
    }



}