/**
 * @file Test for zero as null pointer warinings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Low      | Medium     | High             | P2       | L3    |
 * 
 * @see SEI CERT C Coding Standard: Rule INT36-C. Converting a pointer
 * to integer or integer to pointer
 * https://wiki.sei.cmu.edu/confluence/display/c/INT36-C.+Converting+a+pointer+to+integer+or+integer+to+pointer
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when using '0' as null pointer.
 */
static void qiip_zeroasnullpointer_test(void);


/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_zeroasnullpointer_test(void)
  {
#ifndef QIIP_FIX
    char* string;
    string = (char*) 0;
    if(string == NULL)
      {
        printf("Success!\n");
      }
#else
    char* string;
    string = (char*) NULL;
    if(string == NULL)
      {
        printf("Success!\n");
      }

#endif
  }


signed main()
  {
      qiip_zeroasnullpointer_test();
  }


