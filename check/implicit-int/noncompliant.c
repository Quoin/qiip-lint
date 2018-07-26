/**
 * @file Test for implicit integer declaration warnings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Low      | Unlikely   | Low              | P3       | L3    |
 * 
 * @see SEI CERT C Coding Standard: Rule DCL31-C. Declare identifiers before
 *   using them
 *   https://wiki.sei.cmu.edu/confluence/display/c/ARR30-C.+Do+not+form+or+use+out-of-bounds+pointers+or+array+subscripts
 */


#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Main entry point to program.
 */
signed main(void);


#if !(defined __cplusplus) && !((defined QIIP_FIX) && (1 == QIIP_FIX))
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


/**
 * Definition of object foo.
 */
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
