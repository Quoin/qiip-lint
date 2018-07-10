#include <assert.h>
#include <stdio.h>
  
int main(void) {
  char character = 'H';
  int temp = character;
  int *ip = &temp;
 
  if(ip == &temp){
    printf("Success!\n");
  }
}
