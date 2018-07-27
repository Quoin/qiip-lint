/**
 * @file Test for conversion warnings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | High     | Probable   | Low              | P6       | L2    |
 * 
 * @see SEI CERT C Coding Standard: Rule INT31-C. Ensure that integer
 *   conversions do not result in lost or misinterpreted data
 *   https://wiki.sei.cmu.edu/confluence/display/c/INT31-C.+Ensure+that+integer+conversions+do+not+result+in+lost+or+misinterpreted+data
 */


#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when implicit conversion changes value.
 */
static void qiip_conversion_test(void);

/**
 * Test warning when converting short to char.
 */
static void qiip_shorttocharconversion_test(void);

/**
 * Test warning when converting int to short.
 */
static void qiip_inttoshortconversion_test(void);

/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_conversion_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    signed num = -10;
    num = num + 5;
    unsigned score = num;
    printf("%o", score);
#else
    signed num = -10;
    num = num + 5;
    signed score = num;
    printf("%d", score);
#endif
  }


static void qiip_shorttocharconversion_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    char temp;
    signed short a = 0x80;
	  temp = a;
    printf("%c", temp);
#else
    signed short temp;
	  char a = 0x7f;
	  temp = a;
    printf("%hd", temp);
#endif

  }

static void qiip_inttoshortconversion_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    signed short temp;
    signed a = 0x8000;
    temp = a;
    printf("%hd", temp);
#else
    signed temp;
    signed short a = 0x7fff;
    temp = a;
    printf("%d", temp);
#endif
  }


signed main(void)
  {
    signed const result = EXIT_SUCCESS;
    qiip_conversion_test();
    qiip_shorttocharconversion_test();
    qiip_inttoshortconversion_test();
    return result;
  }
