#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INCHES_PER_POUND 166

int main(void)
{
    printf("To C, or not to C: that is the question.\n");
    srand(time(0));
    int r = rand();
    printf("Random number is %d\n", r);

    /* Compute dimensional weight of box with input */
    float height, length, width, volume, weight;
    printf("Enter height of box: ");
    scanf("%f", &height);
    printf("Enter length of box: ");
    scanf("%f", &length);
    printf("Enter width of box: ");
    scanf("%f", &width);
    
    volume = height * length* width;
    weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;

    printf("Volume (cubic inches): %.2f\n", volume);
    printf("Dimensional weight (pounds): %.3f\n", weight);

    return 0;
}