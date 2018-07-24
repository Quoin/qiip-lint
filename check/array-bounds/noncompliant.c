/**
 * @file Test for array out of bound warnings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | High     | Likely     | High             | P9       | L2    |
 * 
 * @see SEI CERT C Coding Standard: Rule ARR30-C. Do not form or use
 *   out-of-bounds pointers or array subscripts
 *   https://wiki.sei.cmu.edu/confluence/display/c/ARR30-C.+Do+not+form+or+use+out-of-bounds+pointers+or+array+subscripts
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when accessing array from index larger than size.
 */
static void qiip_arrayoutofbound_larger_test(void);

/**
 * Test warning when accessing array from negative index.
 */
static void qiip_arrayoutofbound_negative_test(void);


/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_arrayoutofbound_larger_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    int scores[3] = {8, 7, 9};
    scores[3] = 10;
#else
    int scores[3] = {8, 7, 9};
    scores[2] = 10;
#endif
    printf("The first element of the the array is %d", scores[0]);
  }


static void qiip_arrayoutofbound_negative_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    int scores[3] = {8, 7, 9};
    scores[-1] = 10;
#else
    int scores[3] = {8, 7, 9};
    scores[1] = 10;
#endif
    printf("The first element of the the array is %d", scores[0]);
  }



signed main(void)
  {
      signed const result = EXIT_SUCCESS;
      qiip_arrayoutofbound_larger_test();
      qiip_arrayoutofbound_negative_test();
      return result;
  }

