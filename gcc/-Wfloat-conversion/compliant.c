#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int num = 10;
    int score = abs(num); /* Implicit conversion that reduce precision. */
    if(score == num){
        printf("Success!\n");
    }
    else{
        printf("Failure!\n");
    }
}

