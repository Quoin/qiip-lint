#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Foo ""

int main(){
    char* foo;
    foo = strdup(Foo);
    printf("%s\n", foo);
}