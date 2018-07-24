/**
 * @file Test for shift count overflow warinings.
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
 * Test warning when shifting signed long by count larger than the number of bits exist.
 */
static void qiip_signedlongshiftcountoverflow_test(void);

/**
 * Test warning when left shifting int by count larger than the int size.
 */
static void qiip_intleftshiftcountoverflow_test(void);

/**
 * Test warning when left shifting long by count larger than the long size.
 */
static void qiip_longleftshiftcountoverflow_test(void);

/**
 * Test warning when left shifting unsigned int by count larger than the long size.
 */
static void qiip_unsignedintleftshiftcountoverflow_test(void);

/**
 * Test warning when left shifting unsigned long by count larger than the long size.
 */
static void qiip_unsignedlongleftshiftcountoverflow_test(void);


/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_signedlongshiftcountoverflow_test(void)
  {
#ifndef QIIP_FIX
    signed long a = 10;
    signed long num = a << 10000;
    printf("The number is %ld", num);
#else
    signed long a = 10000;
    signed long num = a << 10;
    printf("The number is %ld", num);
#endif
  }

static void qiip_intleftshiftcountoverflow_test(void)
  {
#ifndef QIIP_FIX
    int a = 1;
    int num = a << 32;
    printf("The number is %ld", num);
#else
    int a = 1;
    int num = a << 10;
    printf("The number is %ld", num);
#endif
  }

static void qiip_longleftshiftcountoverflow_test(void)
  {
#ifndef QIIP_FIX
    long a = 1;
    long num = a << 32;
    printf("The number is %ld", num);
#else
    long a = 1;
    long num = a << 10;
    printf("The number is %ld", num);
#endif
  }

static void qiip_unsignedintleftshiftcountoverflow_test(void)
  {
#ifndef QIIP_FIX
    unsigned int a = 1;
    unsigned int num = a << 32;
    printf("The number is %ld", num);
#else
    unsigned int a = 1;
    unsigned int num = a << 10;
    printf("The number is %ld", num);
#endif
  }

static void qiip_unsignedlongleftshiftcountoverflow_test(void)
  {
#ifndef QIIP_FIX
    unsigned long a = 1;
    unsigned long num = a << 32;
    printf("The number is %ld", num);
#else
    unsigned long a = 1;
    unsigned long num = a << 10;
    printf("The number is %ld", num);
#endif
  }


signed main(void)
  {
      qiip_signedlongshiftcountoverflow_test();
      qiip_intleftshiftcountoverflow_test();
      qiip_longleftshiftcountoverflow_test();
      qiip_unsignedintleftshiftcountoverflow_test();
      qiip_unsignedlongleftshiftcountoverflow_test();
  }
