#include <stdio.h>
#include <stdlib.h>

int main(){
    char string[] = "Hello world!\n";
    printf("%s", string);
    free(string);
}
