/**
 * @file Test for cast alignment warinings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Low      | Probable   | Medium           | P4       | L3    |
 * 
 * @see SEI CERT C Coding Standard: Rule EXP36-C. Do not cast poinsters
 * into more strictly aligned pointer types
 * https://wiki.sei.cmu.edu/confluence/display/c/EXP36-C.+Do+not+cast+pointers+into+more+strictly+aligned+pointer+types
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when making a cast that increase alignment.
 */
static void qiip_castalign_test(void);

/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_castalign_test(void)
  {
#ifndef QIIP_FIX
    char character = 'H';
    int *temp = (int *)&character; /* This cast increase alignment */
    char *cp = (char *)temp;
#else
    char character = 'H';
    int temp = character;
    int *cp = &temp;
#endif
    if(cp == &temp){
      printf("Success!\n");
    }
  }


signed main(void)
  {
    qiip_castalign_test();
  }
