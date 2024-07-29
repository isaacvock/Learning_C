/* Prints int and float values in various formats */
#include <stdio.h>

int main(void)
{
    int i;
    float x;

    i = 4000;
    x=839.21f;
    
    printf("|%d|%5d|%-5d|%5.3d|\n", i , i , i, i);
    printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);


    /* Neat scanf example; 
    scanf pattern matches*/

    int num1, denom1, num2, denom2, result_num, result_denom;
    printf("Enter first fraction: ");
    scanf("%d/%d", &num1, &denom1);

    printf("Enter second fraction: ");
    scanf("%d/%d", &num2, &denom2);

    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;
    printf("The sum is %d/%d\n", result_num, result_denom);

    return 0;
}