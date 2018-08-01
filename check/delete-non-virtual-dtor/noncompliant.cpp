/**
 * @file Test for delete with non-virtual destructor warnings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Low      | Likely     | Low              | P9       | L2    |
 * 
 * @see SEI CERT C Coding Standard: Rule ARR30-C. Do not delete a polymorphic
 *   object without a virtual destructor
 *   https://wiki.sei.cmu.edu/confluence/display/cplusplus/OOP52-CPP.+Do+not+delete+a+polymorphic+object+without+a+virtual+destructor
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif


#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
struct Base
  {
    virtual void f(void);
  };

struct Derived : Base
  {
  };

void f()
  {
    Base *b = new Derived();
    // ...
    delete b;
  }

signed main()
  {
    return EXIT_SUCCESS;
  }
#else
auto main [[gnu::nothrow]] (void) -> signed;


struct base
  {
    virtual ~base(void) = default;
    virtual auto f(void) -> void;
  };
 
struct derived : base {};

auto base::f(void) -> void
  {
    base * const b = new derived();

    std::printf("derived created.\n");

    delete b;
  }

auto main(void) -> signed
  {
    auto const result{EXIT_SUCCESS};
    derived d{};
    std::printf("main.\n");
    return result;
  }
#endif
