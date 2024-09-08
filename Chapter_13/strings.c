#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

/* gets and scanf are trash */
int read_line(char str[], int n);

/* Count the number of spaces in a string */
int count_spaces(const char *s);
int count_spaces2(const char s[]);

int main(void){


    /* Accessing the characters in a string */
    char space_test[15];
    printf("Enter a sentence: ");
    read_line(space_test, 14);
    int scount = count_spaces(space_test);
    printf("The number of spaces is %d\n", scount);
    int scount2 = count_spaces2(space_test);
    printf("Number of spaces by second count is %d\n", scount2);



    /* Custom reader */
    char better_sentence[15];
    printf("Enter a sentence: ");
    read_line(better_sentence, 14);
    printf("%s\n", better_sentence);


    /* Reading strings */
    char sentence[15];
    printf("Enter a sentence: \n");
    scanf("%s", sentence);
    puts(sentence);




    /* Writing strings */
    char str[] = "Are we having fun yet?";
    printf("%s\n", str);
    printf("%.6s\n", str);
    puts(str);


    /* Some string literal stuff */
    printf("When you come to a fork in the road, take it. \
    --Yogi Berra\n");

    char *p;
    p = "abc";

    printf("%s\n", p);
}

int count_spaces2(const char s[]){

    int counter = 0;

    for(int i = 0; s[i] != '\0'; i++){

        if(s[i] == ' '){
            counter++;
        }

    }

    return counter;

}

int count_spaces(const char *s){

    int counter = 0;

    for(; *s != '\0'; s++){

        if(*s == ' '){
            counter++;
        }

    }

    return counter;

}


int read_line(char str[], int n){

    int ch, i = 0;

    while((ch = getchar()) != '\n'){

        if (i < n){

            str[i++] = ch;

        }



    }

    str[i] = '\0';
    return i;

}