#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>

/* Max number of reminders and max reminder length */
#define MAX_REMIND 50
#define MSG_LEN 60


/* gets and scanf are trash */
int read_line(char str[], int n);

/* Count the number of spaces in a string */
int count_spaces(const char *s);
int count_spaces2(const char s[]);

/* Some string idioms */
size_t my_strlen(const char *s);
char *my_strcat(char *s1, const char *s2);
char *my_stroverwrite(char *s1, const char *s2);


int main(int argc, char *argv[]){

    /* Check which strings are planet names*/
    char *planets[] = {"Mercury", "Venus", "Earth",
                       "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto"};

    bool is_planet;
    int planet_index;

    for(int ap = 1; ap < argc; ap++){

        is_planet = false;

        for(int p = 0; p < 9; p++){

            if(strcmp(planets[p], argv[ap]) == 0){

                is_planet = true;
                planet_index = p + 1;
                break;

            }

        }

        if(is_planet){
            printf("%s is planet %d\n", argv[ap], planet_index);
        }else{
            printf("%s is not a planet\n", argv[ap]);
        }
    }


    /* Command line arg parsing */
    for(int a=0; a<argc; a++){
        printf("Argument %d is %s\n", a, argv[a]);
    }

    /* Simulating a ragged array */
    char *raggedy[] = {"Mercury", "Venus", "Earth",
                       "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto"};

    for(int p=0; p<9; p++){
        printf("Planet %d is %s\n", p, raggedy[p]);
    }

    /* String idioms */
    char str_to_test[] = "I am a string!";
    printf("string is %ld long\n", my_strlen(str_to_test));

    char str_to_test2a[100] = "I am a string!";
    char str_to_test2b[100] = "I am a better string";
    char str_to_test3a[100] = "I am a string!";
    char str_to_test3b[100] = "I am a better string";

    printf("str_to_test2a was originally %s\n", str_to_test2a);
    printf("str_to_test3a was originally %s\n", str_to_test3a);

    my_strcat(str_to_test2a, str_to_test2b);
    /* my_stroverwrite(str_to_test3a, str_to_test3b); */

    printf("str_to_test2a is now %s\n", str_to_test2a);
    printf("str_to_test3a is now %s\n", str_to_test3a);



    /* One-Month Reminder List */
    char reminders[MAX_REMIND][MSG_LEN+3];
    char day_str[3], msg_str[MSG_LEN + 1];
    int rcount = 0;
    int day = 1;
    int i, j;

    for(;;){

        if (rcount == MAX_REMIND){
            printf("At capacity!");
            break;
        }

        printf("Enter a day and a reminder: ");
        scanf("%2d", &day);
        if(day == 0){
            break;
        }

        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        /* Insert msg_str where it belongs */
        for(i = 0; i<rcount; i++){

            if(strcmp(day_str, reminders[i]) < 0){
                break;
            }

        }
        for(j = rcount; j > i; j--){
            strcpy(reminders[j], reminders[j-1]);
        }
        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);
        
        rcount++;

    }

    printf("\nDay Reminder\n");
    for(i = 0; i < rcount; i++){
        printf("%s\n", reminders[i]);
    }


    /* Playing around with the string library */
    char str1[15];
    char str2[] = "abcdefghijklmnopqrst";

    strncpy(str1, str2, sizeof(str1) - 1);
    str1[sizeof(str1) - 1] = '\0';
    printf("str1 is: %s\n",str1);

    int len = strlen(str1);
    printf("str1 is %d characters long\n", len);

    char str3[15 + sizeof(str2) - 1];
    strcpy(str3, str1);
    printf("str3 is %s\n", str3);
    strcat(str3, str2);
    printf("str3 is now %s\n", str3);

    if(strcmp(str1, str2) < 0){

        printf("str1 is less than str2\n");

    }else if(strcmp(str1, str2) > 0){

        printf("str1 is greater than str2\n");

    }else{
        
        printf("str1 is equal to str2\n");

    }


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

size_t my_strlen(const char *s){

    size_t n = 0;
    size_t n2 = 0;

    while(*s++){
        n2++;
    }

    if(n2 != 14){
        printf("Oh fuck\n");
        printf("n is %ld\n", n);
        printf("n2 is %ld\n", n2);
    }else{
        printf("Success\n");
    }

    return n2;
}

char *my_strcat(char *s1, const char *s2){

    char *p = s1;

    while(*p){
        p++;
    }

    while(*p++ = *s2++){
        ;
    }

    return s1;

}


char *my_stroverwrite(char *s1, const char *s2){


    *s1 = *s2;

    while(*s2++ && *s1++){

        *s1 = *s2;

    }

    return(s1);

}