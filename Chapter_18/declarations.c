#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/* static can make programs more efficient */
char digit_to_hex_char(int digit){
    static const char hex_chars[16] = "0123456789ABCDEF";
    return hex_chars[digit];
}

int main(int argc, char *argv[]){

    /* Make sure argument was provided */
    if(argc < 2){
        printf("Didn't include digit to convert to hex!\n");
        return 1;
    }else if(argc > 2){
        printf("There are additional arguments that won't be used!\n");
        printf("Assuming that 2nd argument is digit to convert!\n");
    }


    int d = atoi(argv[1]);
    char dH = digit_to_hex_char(d);

    printf("%d is %c\n", d, dH);

    return 0;

}