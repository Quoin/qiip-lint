/**
 * @file Test for division by zero warinings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Low      | Likely     | Medium           | P6       | L2    |
 * 
 * @see SEI CERT C Coding Standard: Rule INT33-C. Ensure that division
 * and remainder operations do not result in divide-by-zero errors
 * https://wiki.sei.cmu.edu/confluence/display/c/INT33-C.+Ensure+that+division+and+remainder+operations+do+not+result+in+divide-by-zero+errors
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <limits.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when dividing constant by zero.
 */
static void qiip_divbyzero_test(void);


/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_divbyzero_test(void)
  {
#ifndef QIIP_FIX
    int a = 3;
    int result;
    result = a / 0; /*Division by zero error */
#else
    int a = 3;
    int result;
    result = a / 2;
#endif
    printf("The result is %d.\n", result);
  }


signed main(void)
  {
      qiip_divbyzero_test();
  }

