#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


/* Concatenate function */
char *concat(const char *s1, const char *s2);

int main(void){

    /* Dynamically allocated arrays*/
    int *a;
    int n = 5;
    a = malloc(n * sizeof(int));
    for(int i = 0; i < n; i ++){
        a[i] = 0;
    }

    free(a);

    /* Dynamically allocated strings */
    char *s1 = "I am a string. ";
    char *s2 = "I am also a string";
    char *result = concat(s1, s2);

    printf("Final string is: %s\n", result);
}

/* Concatenate strings without changing either */
char *concat(const char *s1, const char *s2){
    char *result;
    
    result = malloc(strlen(s1) + strlen(s2) + 1);
    if(result == NULL){
        printf("Error: malloc failed in concat\n");
        exit(EXIT_FAILURE);
    }
    strcpy(result, s1);
    strcat(result, s2);
    return(result);
}