/**
 * @file Test for free nonheap object warning (-W'free-nonheap-object').
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | High     | Likely     | Medium           | P18      | L1    |
 * 
 * @see SEI CERT C Coding Standard: Rule MEM34-C. Only free memory allocated
 *   dynamically
 *   https://wiki.sei.cmu.edu/confluence/display/c/MEM34-C.+Only+free+memory+allocated+dynamically
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>


/**
 * Main entry point to program.
 */
signed main(void) __attribute__((nothrow));


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when freeing non-heap objects.
 */
static void qiip_freenonheapobject_test(void) __attribute__((nothrow));


#ifdef __cplusplus
}
#endif


static void qiip_freenonheapobject_test(void)
  {
    char const msg[] = "hello, world";

#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    char string[sizeof msg] = "";
#else
    char * const __restrict__ string = (char *)malloc(sizeof msg);
#endif

    strcpy(string, msg);
    printf("string=\"%s\".\n", string);
    free(string);
  }


signed main(void)
  {
    signed const result = EXIT_SUCCESS;

    qiip_freenonheapobject_test();

    return result;
  }
