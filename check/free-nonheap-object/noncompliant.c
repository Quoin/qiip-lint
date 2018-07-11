/**
 * @file Test for free nonheap object warinings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | High     | Likely     | Medium           | P18      | L1    |
 * 
 * @see SEI CERT C Coding Standard: Rule MEM34-C. Only free memory allocated
 * dynamically
 * https://wiki.sei.cmu.edu/confluence/display/c/MEM34-C.+Only+free+memory+allocated+dynamically
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when freeing objects that are nonheap.
 */
static void qiip_freenonheapobject_test(void);


/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_freenonheapobject_test(void)
  {
#ifndef QIIP_FIX
    char string[] = "Hello world!\n";
    printf("%s", string);
    free(string);
#else
    char* string = (char*) malloc(sizeof(char) * 20);
    strcpy(string, "Hello world!\n");
    printf("%s", string);
    free(string);
#endif
  }


signed main()
  {
      qiip_freenonheapobject_test();
  }

