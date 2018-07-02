#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float num = 10.00;
    num = num + 5.5;
    int score = fabsf(num); /* Implicit conversion that reduce precision. */
    if(score == num){
        printf("Success!\n");
    }
    else{
        printf("Failure!\n");
    }
}

