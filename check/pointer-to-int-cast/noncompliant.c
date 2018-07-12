/**
 * @file Test for pointer to int cast warinings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Low      | Probable   | High             | P2       | L3    |
 * 
 * @see SEI CERT C Coding Standard: Rule INT36-C. Converting a pointer to
 * integer or integer to pointer
 * https://wiki.sei.cmu.edu/confluence/display/c/INT36-C.+Converting+a+pointer+to+integer+or+integer+to+pointer
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when casting a pointer to integer.
 */
static void qiip_pointertointcast_test(void);


/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_pointertointcast_test(void)
  {
#ifndef QIIP_FIX
    char pointer[] = "c";
    unsigned int num = (unsigned int) pointer;
    printf("The number is %d", num);
#else
    char pointer[] = "c";
    uintptr_t num = (uintptr_t) pointer;
    printf("The number is %ld", num);
#endif
  }


signed main()
  {
      qiip_pointertointcast_test();
  }
