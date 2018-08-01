/**
 * @file Test for invalid offset of warnings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Medium   | Unlikely   | Medium           | P4       | L3    |
 * 
 * @see SEI CERT C Coding Standard: Rule EXP59-CPP. Use offsetof() on
 *   valid types and members
 *   https://wiki.sei.cmu.edu/confluence/display/cplusplus/EXP59-CPP.+Use+offsetof%28%29+on+valid+types+and+members
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

#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
struct D
      {
        virtual void f() {}
        int i;
      };
  
void f()
  {
    size_t off = offsetof(D, i);
    printf("The offset is %lu", off);
  }
#else
struct D
  {
    void f(void);
    struct InnerStandardLayout
      {
        int i;
      } inner;
  };
 
void D::f(void)
  {
    auto const off{offsetof(D::InnerStandardLayout, i)};
    std::printf("The offset is %lu", off);
  }
#endif

signed main()
  {
    return EXIT_SUCCESS;
  }

