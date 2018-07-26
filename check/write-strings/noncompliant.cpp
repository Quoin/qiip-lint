/**
 * @file Test for write string warnings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Low      | Likely     | Low              | P9       | L2    |
 * 
 * @see SEI CERT C Coding Standard: Rule STR30-C. Do not attempt to modify
 *   string literals
 *   https://wiki.sei.cmu.edu/confluence/display/c/STR30-C.+Do+not+attempt+to+modify+string+literals
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when converting string literals to 'char*'.
 */
static void qiip_writestring_test(void);


/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_writestring_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    char* string = "Hello world!\n";
    printf("%s", string);
#else
    char string[] = "Hello world!\n";
    printf("%s", string);
#endif
  }


signed main()
  {
    signed const result = EXIT_SUCCESS;
    qiip_writestring_test();
    return result;
  }

