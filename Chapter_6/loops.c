#include <stdio.h>

int main(void){

    int i = 1;

    while(i > 0) {
        i--;
        printf("One more loop...\n");
    }

    /* Table of squares */

    int scount;
    printf("This program prints a table of squares.\n");
    printf("Enter a number of squares to print: ");
    scanf("%d", &scount);

    int counter = 1;
    while(counter <= scount){

        printf("%d      %d\n", counter, counter * counter);
        counter++;

    }


    /* Now on to the summation program */

    int sum = 0;
    printf("This program sums a series of integers.\n");

    int check = 0;
    
    printf("Enter integers (0 to terminate): ");
    while (check == 0){

        int current_value;
        scanf("%d", &current_value);

        if(current_value == 0){
            check = 1;
        }else{
            sum = sum + current_value;
        }

    }

    printf("Sum is: %d\n", sum);

    /* Demostrating do while loops */
    int j = 10;
    do {
        printf("T minus %d and counting\n", j);
        --j;
    } while (j > 0);


    /* Demonstrating for loops */
    int k;
    for(k = 10; k > 0; k--){
        printf("T minus %d and counting\n", k);
    }


    int sqs;
    printf("This is a better way to print a table of squares\n");
    printf("How many squares do you mant me to print: ");
    scanf("%d", &sqs);

    for(int m = 1; m <= sqs; m++){

        printf("%d     %d\n", m, m * m);

    }


    /* Balancing a checkbook */
    printf("*** ACME checkbook-balancing program ***\n");
    printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n");

    int cmd;
    float balance = 0.0f, credit, debit;

    for( ; cmd != 4; ){

        printf("Enter command: ");
        scanf("%d", &cmd);

        switch(cmd){
            case 0:
                balance = 0.0f;
                break;
            case 1:
                printf("Enter amount of credit: ");
                scanf("%f", &credit);
                balance += credit;
                break;
            case 2:
                printf("Enter amount of debit: ");
                scanf("%f", &debit);
                balance -= debit;
                break;
            case 3:
                printf("Current balance: $%.2f\n", balance);
                break;
            case 4:
                break;
            default:
                printf("Invalid command!\n");
                printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n");
        }

    }


    return(0);

}