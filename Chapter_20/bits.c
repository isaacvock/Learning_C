#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(void){

    /* Bitwise shifts */

    unsigned short i, j;

    i = 13; /* i is now 13     (0000000000001101)*/
    j = i << 2; /* j is now 52 (0000000000110100)*/ 
    j = i >> 2; /* j is now 3  (0000000000000011)*/

    printf("j is %hu\n", j);
    printf("i is %hu\n", i);

    i <<= 2; /* is now 52 */

    printf("j is %hu\n", j);
    printf("i is %hu\n", i);

    /* Other bitwise operators */

    i = 5; /*  ...00101 */
    j = 10; /* ...01010*/
    unsigned short k = ~i; /* Sets all bits to 1s that were 0s and vice versa*/
    printf("i is %hu\n", i);
    printf("j is %hu\n", j);
    printf("k is %hu\n", k);
    k = i & j; /* Guessing this is 0 */
    printf("%hu & %hu is %hu\n", i, j, k);
    k = i ^ j; /* Guessing this is 15 */
    printf("%hu ^ %hu is %hu\n", i, j, k);
    k = i | j; /* Guessing this is 15 */
    printf("%hu | %hu is %hu\n", i, j, k);

    /* Bit manipulation*/

    i = 0x000;
    i |= 0x0010; /* Will flip the 5th bit because 0x0010 = 0000000000010000*/
    printf("i is %hu\n", i);

    j = 0x0010;
    i &= ~(i << j); 
    printf("i is %hu\n", i);


}