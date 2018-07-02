#include <stdio.h>
#include <stdlib.h>

int main(){
    int num = -10;
    num = num + 5;
    unsigned score = num; /* Implicit conversion that changes value. */
    if(score < 0){
        printf("Success!\n");
    }
    else{
        printf("Failure!\n");
    }
}

