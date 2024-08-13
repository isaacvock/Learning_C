#include <stdio.h>

int main(void)
{
    float trade, commission;

    printf("Enter value of trade: ");
    scanf("%f", &trade);

    if(trade < 2500.00f){
        commission = 30.00f + 0.017f*trade;
    } else if(trade <= 6250.00f){
        commission = 56.00f + 0.0066f*trade;
    } else if(trade <= 20000.00f){
        commission = 76.00f + 0.0034f*trade;
    } else if(trade <= 50000.00f){
        commission = 100.00f + 0.0022f*trade;
    } else if(trade <= 500000.00f){
        commission = 155.00f + 0.0011f*trade;
    }else{
        commission = 255.00f + 0.0009f*trade;
    }

    if(commission < 39.00f){
        commission = 39.00f;
    }

    printf("Commission: %.2f\n", commission);

    return(0);

}