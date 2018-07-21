/**
 * @file Test for One Definition Rule volations warinings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Hight    | Unlikely   | High             | P3       | L3    |
 * 
 * @see SEI CERT C Coding Standard: Rule EXP59-CPP. Obey the one-definition
 * rule
 * https://wiki.sei.cmu.edu/confluence/display/cplusplus/DCL60-CPP.+Obey+the+one-definition+rule
 * 
 */


#include <cstdlib>


/**
 * Main entry point to program.
 */
signed main(void);

/**
 * S.h
 */
struct S {
  int a;
};
  

signed main(void)
  {
    return EXIT_SUCCESS;
  }

