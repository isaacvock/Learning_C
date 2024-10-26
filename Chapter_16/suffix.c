#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store suffixes and their starting positions
struct Suffix {
    int index;
    const char *suffix;
};

// Comparator function for sorting suffixes lexicographically
int suffixCompare(const void *a, const void *b) {
    return strcmp(((struct Suffix *)a)->suffix, ((struct Suffix *)b)->suffix);
}

// Function to build suffix array
void buildSuffixArray(const char *txt, int n, int suffixArr[]) {
    struct Suffix suffixes[n];

    // Populate suffix array with suffixes and their starting indices
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].suffix = txt + i;
    }

    // Sort suffixes using qsort and custom comparator
    qsort(suffixes, n, sizeof(struct Suffix), suffixCompare);

    // Store indices in suffix array
    for (int i = 0; i < n; i++) {
        suffixArr[i] = suffixes[i].index;
    }
}

// Utility function to print the suffix array
void printSuffixArray(const int suffixArr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", suffixArr[i]);
    }
    printf("\n");
}

int main() {
    const char *txt = "GATTACA";
    int n = strlen(txt);
    int suffixArr[n];

    buildSuffixArray(txt, n, suffixArr);
    printf("Suffix Array for '%s':\n", txt);
    printSuffixArray(suffixArr, n);

    return 0;
}
