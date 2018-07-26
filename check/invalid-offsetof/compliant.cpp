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


#include <cstdio>
#include <cstdlib>
#include <cstddef>


/**
 * Main entry point to program.
 */
auto main(void) -> signed;


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

auto main(void) -> signed
  {
    auto const result{EXIT_SUCCESS};

    D tmp{};
    tmp.f();

    return result;
  }

