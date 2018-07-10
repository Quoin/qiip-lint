#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 3;
    int b = 0;
    int result;
    result = a / b; /*Division by zero error */
    printf("The result is %d.\n", result);
}
