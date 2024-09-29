#include <stdio.h>
#include <string.h>

/* Macros, some cursed */
#define LOOP for(;;)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define PRINT_INT(n) printf(#n " = %d\n", n)
#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
    return x > y ? x : y;       \
}
#define ECHO(s) (fgets(s, sizeof(s), stdin), puts(s))

GENERIC_MAX(float)

int main(int argc, char *argv[]){

    int echo_flag;
    char str[60];
    printf("Echo string you provide? 1 = yes, 0 = no: ");
    scanf("%d", &echo_flag);

    if(echo_flag == 1){

        printf("echo_flag was 1\n");
        printf("Provide a string: ");
        getchar();
        ECHO(str);

    }else{

        printf("echo_flag was 0");
        printf("Provide a string: ");
        getchar();
        fgets(str, sizeof(str), stdin);

    }

    printf("Hello directives\n");

    int i = 1;
    LOOP{
        i++;
        if(i > 3){
            printf("Macros are for punks\n");
            break;
        }
    }

    int m = MAX(1,2);
    printf("max of 1 and 2 is %d\n", m);
    i = 1;

    PRINT_INT(m/i);

    float iflo = 1.5;
    float jflo = 2.5;
    float mflo = float_max(iflo, jflo);
    printf("max of 1.5 and 2.5 is %f\n", mflo);
}

