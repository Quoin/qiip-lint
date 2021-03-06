/**
 * @file Test for pointer to int cast warnings.
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
 */

#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when casting a pointer to integer.
 */
static void qiip_pointertointcast_test(void);


/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_pointertointcast_test(void)
  {
#if !(defined __cplusplus) && !((defined QIIP_FIX) && (1 == QIIP_FIX))
    char pointer[] = "c";
    unsigned int num = (unsigned int) pointer;
    printf("The number is %u", num);
#else
    char pointer[] = "c";
    uintptr_t num = (uintptr_t) pointer;
    printf("num=\"%" PRIuPTR "\".\n", num);
#endif
  }


signed main(void)
  {
    signed const result = EXIT_SUCCESS;
    qiip_pointertointcast_test();
    return result;
  }
