/**
 * @file Test for implicit function declaration warnings.
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

#if ((defined __cplusplus) || ((defined QIIP_FIX) && (1 == QIIP_FIX)))
  #include <string.h>
#endif


/**
 * Main entry point to program.
 */
signed main(void) __attribute__((nothrow));


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Test warning when calling function without prototype in scope.
 */
static void qiip_implicitfunctiondeclaration_test(void) __attribute__((nothrow));

#ifdef __cplusplus
}
#endif


signed main(void)
  {
    signed const result = EXIT_SUCCESS;

    qiip_implicitfunctiondeclaration_test();

    return result;
  }


static void qiip_implicitfunctiondeclaration_test(void)
  {
    char const msg[] = "hello, world";
    size_t const len = strlen(msg);
    printf("len=\"%zu\".\n", len);
  }
