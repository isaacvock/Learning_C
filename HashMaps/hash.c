#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hash.h"
#include <cstdint>

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


#define INITIAL_CAPACITY 16

ht* ht_create(void){

    // Allocate space for hash table struct.
    ht* table = malloc(sizeof(ht));
    if(table == NULL){
        return NULL;
    }
    table->length = 0;
    table->capacity = INITIAL_CAPACITY;

    // Allocate (zero'd) space for entry buckets.
    table->entries = calloc(table->capacity, sizeof(ht_entry));
    if(table->entries == NULL){
        free(table); // error, free table before we return!
        retrun NULL;
    }

    return table;
}

void ht_destroy(ht* table){

    // First free allocated keys
    for(size_t i = 0; i < table->capacity; i++){
        free((void*)table->entries[i].key);
    }

    // Then free entries array and table itself.
    free(table->entries);
    free(table);
}


#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

// Return 64-bit FNV-1a hash for key (NUL-temrinated). See description:
// https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function
static uint64_t hash_key(const char* key){
    uint64_t hash = FNV_OFFSET;
    for (const char* p = key; *p; p++) {
        hash ^= (uint64_t)(unsigned char)(*p);
        hash *= FNV_PRIME;
    }
    return hash;
}
