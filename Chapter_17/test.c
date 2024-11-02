#include <stdio.h>

int main(void){

    int i, j;

    for(i = 0; i<0; i++){
        printf("Entered the i loop!\n");
    }

    for(j = 0; j > i; j--){
        printf("Entered the j loop!\n");
    }

}