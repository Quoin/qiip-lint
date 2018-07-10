#include <assert.h>
#include <stdio.h>
  
int main(void) {
  char character = 'H';
  int *temp = (int *)&character; /* This cast increase alignment */
  char *cp = (char *)temp;
 
  if(cp == &character){
    printf("Success!\n");
  }
}
