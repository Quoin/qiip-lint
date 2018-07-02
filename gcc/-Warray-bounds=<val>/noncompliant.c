#include <stdlib.h>
#include <stdio.h>

signed main()
{
    int scores[3] = {8, 7, 9};
    int num;
    scores[3] = 10;
    printf("Please input the number of the score:");
    scanf("%d", &num);
    if(num <= 3){
        printf("The %dth score is %d\n", num, scores[num - 1]);
    }
    else{
        printf("Number out of range.");
    }
    
    
}

