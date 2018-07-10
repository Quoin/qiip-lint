#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(){
    volatile uintptr_t iptr = 0xdeadbeef;
    unsigned int *ptr = (unsigned int *)iptr;
}
