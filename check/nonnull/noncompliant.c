/**
 * @file Test for non-NULL warnings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Medium   | Probable   | High             | P4       | L3    |
 * 
 * @see SEI CERT C Coding Standard: Rule ARR30-C. Do not form or use
 *   out-of-bounds pointers or array subscripts
 *   https://wiki.sei.cmu.edu/confluence/display/c/ARR30-C.+Do+not+form+or+use+out-of-bounds+pointers+or+array+subscripts
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
 * Test warning when NULL is passed to argument slots marked as requiring non-NULL.
 */
static void qiip_nonnull_test(void);

/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_nonnull_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    printf(NULL);
#else
    char const * const msg = "hello, world";
    printf("msg=\"%s\".\n", msg);
#endif
  }


signed main(void)
  {
    signed const result = EXIT_SUCCESS;
    qiip_nonnull_test();
    return result;
  }

