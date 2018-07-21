/**
 * @file Test for implicit integer declaration warinings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Low      | Unlikely   | Low              | P3       | L3    |
 * 
 * @see SEI CERT C Coding Standard: Rule DCL31-C. Declare identifiers before
 * using them
 * https://wiki.sei.cmu.edu/confluence/display/c/ARR30-C.+Do+not+form+or+use+out-of-bounds+pointers+or+array+subscripts
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
extern "C" {
#endif

#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
extern foo;
#else
extern signed foo;
#endif 

/**
 * Test warning when implicitly declaring integer.
 */
static void qiip_implicitint_test(void);

#ifdef __cplusplus
}
#endif


signed foo = 0;


static void qiip_implicitint_test(void)
  {
    printf("foo=\"%d\".\n", foo);
  }

signed main(void)
  {
    signed const result = EXIT_SUCCESS;

    qiip_implicitint_test();

    return result;
  }
