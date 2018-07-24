/**
 * @file Test for shift count negative warinings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Low      | Unlikely   | Medium           | P2       | L3    |
 * 
 * @see SEI CERT C Coding Standard: Rule INT34-C. Do not shift an expression
 * by a negative number of bits or by greater than or equal to the number of
 * bits that exist in the operant
 * https://wiki.sei.cmu.edu/confluence/display/c/INT34-C.+Do+not+shift+an+expression+by+a+negative+number+of+bits+or+by+greater+than+or+equal+to+the+number+of+bits+that+exist+in+the+operand
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when shifting signed long by negative count.
 */
static void qiip_signedlongshiftcountnegative_test(void);

/**
 * Test warning when right shifting int by negative count.
 */
static void qiip_intrightshiftcountnegative_test(void);

/**
 * Test warning when left shifting int by negative count.
 */
static void qiip_intleftshiftcountnegative_test(void);


/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_signedlongshiftcountnegative_test(void)
  {
#ifndef QIIP_FIX
    signed long a = 10000;
    signed long num = a << -10;
    printf("The number is %ld", num);
#else
    signed long a = 10000;
    signed long num = a << 10;
    printf("The number is %ld", num);
#endif
  }

static void qiip_intrightshiftcountnegative_test(void)
  {
#ifndef QIIP_FIX
    int a = 1;
    int num = a >> -1;
    printf("The number is %ld", num);
#else
    int a = 1;
    int num = a >> 10;
    printf("The number is %ld", num);
#endif
  }

static void qiip_intleftshiftcountnegative_test(void)
  {
#ifndef QIIP_FIX
    int a = 1;
    int num = a << -1;
    printf("The number is %ld", num);
#else
    int a = 1;
    int num = a << 10;
    printf("The number is %ld", num);
#endif
  }


signed main(void)
  {
      qiip_signedlongshiftcountnegative_test();
      qiip_intrightshiftcountnegative_test();
  }
