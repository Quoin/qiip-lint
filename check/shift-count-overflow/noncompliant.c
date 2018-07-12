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
 * Test warning when shifting expressions by count larger than the number of bits exist.
 */
static void qiip_shiftcountoverflow_test(void);


/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void qiip_shiftcountoverflow_test(void)
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


signed main()
  {
      qiip_shiftcountoverflow_test();
  }
