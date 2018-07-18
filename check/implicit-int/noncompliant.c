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


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when implicitly declaring integer.
 */
static void qiip_implicitint_test(void);


/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_implicitint_test(void)
  {
#ifndef QIIP_FIX
    extern foo;
#else
    extern int foo;
#endif 
  }

signed main()
  {
      qiip_implicitint_test();
  }

