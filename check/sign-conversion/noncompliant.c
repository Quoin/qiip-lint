/**
 * @file Test for sign conversion warnings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | High     | Probable   | Low              | P6       | L2    |
 * 
 * @see SEI CERT C Coding Standard: Rule INT31-C. Ensure that integer
 *   conversions do not result in lost or misinterpreted data
 *   https://wiki.sei.cmu.edu/confluence/display/c/INT31-C.+Ensure+that+integer+conversions+do+not+result+in+lost+or+misinterpreted+data
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when implicit sign conversion changes value.
 */
static void qiip_signconversion_test(void);


/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_signconversion_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    int num = -10;
    num = num + 5;
    unsigned score = num;
    printf("%o", score);
#else
    int num = -10;
    num = num + 5;
    signed score = num;
    printf("%d", score);
#endif
  }


signed main(void)
  {
    signed const result = EXIT_SUCCESS;
    qiip_signconversion_test();
    return result;
  }

