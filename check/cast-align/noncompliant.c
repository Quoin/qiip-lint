/**
 * @file Test for cast alignment warning (-W'cast-align').
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Low      | Probable   | Medium           | P4       | L3    |
 * 
 * @see SEI CERT C Coding Standard: Rule EXP36-C. Do not cast pointers
 *   into more strictly aligned pointer types
 *   https://wiki.sei.cmu.edu/confluence/display/c/EXP36-C.+Do+not+cast+pointers+into+more+strictly+aligned+pointer+types
 */


#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


/**
 * Main entry point to program.
 */
signed main(void) __attribute__((nothrow));


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Test warning when making a cast that increases alignment.
 */
static void qiip_castalign_test(void) __attribute__((nothrow));

#ifdef __cplusplus
}
#endif


static void qiip_castalign_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    char const character = 'H';

    /* This cast increase alignment */
    signed const * const tmp = (signed const *)&character;

    char const * const cp = (char const *)tmp;
    printf("cp=\"%p\".\n", cp);
#else
    char const character = 'H';
    signed const tmp = character;
    signed const * const cp = &tmp;
    printf("cp=\"%p\" tmp=\"%d\".\n", (void const *)cp, tmp);
#endif
  }


signed main(void)
  {
    signed const result = EXIT_SUCCESS;
    qiip_castalign_test();
    return result;
  }
