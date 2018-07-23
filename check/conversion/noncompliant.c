/**
 * @file Test for conversion warinings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | High     | Probable   | Low              | P6       | L2    |
 * 
 * @see SEI CERT C Coding Standard: Rule INT31-C. Ensure that integer
 * conversions do not result in lost or misinterpreted data
 * https://wiki.sei.cmu.edu/confluence/display/c/INT31-C.+Ensure+that+integer+conversions+do+not+result+in+lost+or+misinterpreted+data
 * 
 */

#include <stdlib.h>
#include <stdio.h>
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
#ifndef QIIP_FIX
    int num = -10;
    num = num + 5;
    unsigned score = num;
#else
    int num = -10;
    num = num + 5;
    signed score = num;
#endif
    printf("%d", score);
  }


static void qiip_shorttocharconversion_test(void)
  {
#ifndef QIIP_FIX
    char temp;
    short a = 0x80;
	  temp = a;
    printf("%c", temp);
#else
    short temp;
	  char a = 0x7f;
	  temp = a;
    printf("%hd", temp);
#endif

  }

static void qiip_inttoshortconversion_test(void)
  {
#ifndef QIIP_FIX
    short temp;
    int a = 0x8000;
	  temp = a;
    printf("%hd", temp);
#else
    int temp;
  	short a = 0x7fff;
	  temp = a;
    printf("%d", temp);
#endif

  }



signed main()
  {
      qiip_conversion_test();
      qiip_shorttocharconversion_test();
      qiip_inttoshortconversion_test();
  }


