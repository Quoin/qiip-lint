/**
 * @file Test for float implicit conversion warnings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Low      | Unlikely   | Low              | P3       | L3    |
 * 
 * @see SEI CERT C Coding Standard: Rule FLP34-C. Ensure that floating-point
 *   conversions are within range of the new type
 *   https://wiki.sei.cmu.edu/confluence/display/c/FLP34-C.+Ensure+that+floating-point+conversions+are+within+range+of+the+new+type
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when implicitly converting floating-point to type with less precision.
 */
static void qiip_floatconversion_test(void);


/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_floatconversion_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    float num = 10.0;
    num = num + 5.5;
    int score = fabsf(num); /* Implicit conversion that reduce precision. */
#else
    int num = 10;
    int score = abs(num);
#endif
    if(score == num)
      {
        printf("Success!\n");
      }
    else
      {
        printf("Failure!\n");
      }
}


signed main(void)
  {
    signed const result = EXIT_SUCCESS;
    qiip_floatconversion_test();
    return result;
  }

