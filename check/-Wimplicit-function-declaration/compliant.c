#include <stdlib.h>
int main(){
    char* string = (char*) malloc(sizeof(char));
    free(string);
}