#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main(void){

    int i, j, k;

    i = 1;
    j = 2;
    k = i > j ? i : j;
    printf("k is now: %d\n",k);
    k = (i >= 0 ? i: 0) + j;
    printf("k is now: %d\n",k);

    int flag;
    flag = 0;
    if (flag == TRUE){
        printf("flag is TRUE\n");
    }else{
        printf("flag is FALSE\n");
    }

    int grade;
    printf("What is your grade: ");
    scanf("%d", &grade);

    switch(grade) {
        case 4: printf("Excellent\n");
                break;     
        case 3: printf("Good\n");
                break;
        case 2: printf("Fine\n");
                break;
        case 1: printf("Oh shit\n");
                break;
        case 0: printf("Bye\n");
                break;
        default: printf("Illegal grade\n");
                break;
    }

    return(0);
}