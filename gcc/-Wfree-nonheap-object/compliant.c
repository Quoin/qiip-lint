#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* string = (char*) malloc(sizeof(char) * 20);
    strcpy(string, "Hello world!\n");
    printf("%s", string);
    free(string);
}
