#include <stdio.h>

/* Macros, some cursed */
#define LOOP for(;;)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define PRINT_INT(n) printf(#n " = %d\n", n)
#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
    return x > y ? x : y;       \
}

GENERIC_MAX(float)

int main(int argc, char *argv[]){
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

