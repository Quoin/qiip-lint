#include <stdio.h>
#include <stdlib.h>

int main(){
    int num = -10;
    num = num + 5;
    signed score = num;
    if(score < 0){
        printf("Success!\n");
    }
    else{
        printf("Failure!\n");
    }
}

