// Count number of unique words in sentence and total # of unique words
// Example:
// $ echo 'foo bar the bar bar bar the' | ./count
// foo 1
// bar 4
// the 2
// 3

#include <stdio.h>
#include "hash.h"

void exit_nomem(void){
    fprintf(stderr, "out of memory\n");
    exit(1);
}

int main(void){

    ht* counts = ht_create();
    if(counts ==  NULL){
        exit_nomem();
    }

    // Read next word from stdin (at most 100 chars)
    char word[101];
    while(scanf("%100s", word) != EOF){
        // Look up word.
        void* value = ht_get(counts, word);
        if(value != NULL){
            // Already exists, increment int that value points to
            int *pcount = (int*)value;
            (*pcount)++;
            continue;
        }

        // Word not found
        int* pcount = malloc(sizeof(int));
        if(pcount == NULL){
            exit_nomem();
        }
        *pcount = 1;
        if (ht_set(counts, word, pcount) == NULL){
            exit_nomem();
        }

    }

    // Print out words and frequencies, freeing values as we go.
    hti it = ht_iterartor(counts);
    while (ht_next(&it)){
        printf("%s %d\n", it.key, *(int*)it.value);
        free(it.value);
    }

    // Show the number of unique words
    printf("%d\n", (int)ht_length(counts));

    ht_destroy(counts);
    return 0;

}

