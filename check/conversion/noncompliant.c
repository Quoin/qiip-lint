/**
 * @file Test for conversion warinings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | High     | Probable   | Low              | P6       | L2    |
 * 
 * @see SEI CERT C Coding Standard: Rule INT31-C. Ensure that integer
 * conversions do not result in lost or misinterpreted data
 * https://wiki.sei.cmu.edu/confluence/display/c/INT31-C.+Ensure+that+integer+conversions+do+not+result+in+lost+or+misinterpreted+data
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when implicit conversion changes value.
 */
static void qiip_conversion_test(void);


/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_conversion_test(void)
  {
#ifndef QIIP_FIX
    int num = -10;
    num = num + 5;
    unsigned score = num;
#else
    int num = -10;
    num = num + 5;
    signed score = num;
#endif
    if(score < 0)
      {
        printf("Success!\n");
      }
    else
      {
        printf("Failure!\n");
      }
  }


signed main()
  {
      qiip_conversion_test();
  }

