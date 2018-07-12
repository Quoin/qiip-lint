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

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <cstddef>

#ifdef __cplusplus
extern "C" {
#endif



/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif



/**
 * a.cpp
 */
struct S
  {
    int a;
  };
  
/**
 * b.cpp
 */
class S
  {
public:
    int a;
  };

signed main()
  {
    return EXIT_SUCCESS;
  }

