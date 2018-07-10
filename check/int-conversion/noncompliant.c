/**
 * @file Test for integer conversion warnings.
 *
 * @par Risk Assessment
 *
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Low      | Probable   | High             | P2       | L3    |
 *
 * @see SEI CERT C Coding Standard: Rule INT36-C. Converting a pointer to
 *   integer or integer to pointer
 *   https://wiki.sei.cmu.edu/confluence/display/c/INT36-C.+Converting+a+pointer+to+integer+or+integer+to+pointer
 *
 * @see MISRA C:2012: Rule 11.4 A conversion should not be performed between a
 *   pointer to object and an integer type.
 */


#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when assigning integer literal to a pointer.
 */
static void qiip_intconversion_literal_test(void);

/**
 * Test warning when assigning integer variable to a pointer.
 */
static void qiip_intconversion_variable_test(signed arg);


/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_intconversion_literal_test(void)
  {
#ifndef QIIP_FIX
    void const * const ptr = 1;
#else
    void const * const ptr = NULL;
#endif
  
    printf("ptr=\"%p\".\n", ptr);
  }


static void qiip_intconversion_variable_test(signed const arg)
  {
#ifndef QIIP_FIX
    void const * const ptr = arg;
    printf("arg=\"%d\" ptr=\"%p\".\n", arg, ptr);
#else
    /* There is no good fix. Explicit conversion is a bad idea. */
    printf("arg=\"%d\".\n", arg);
#endif
  }


signed main(void)
  {
    qiip_intconversion_literal_test();
    qiip_intconversion_variable_test(10);
    return EXIT_SUCCESS;
  }
