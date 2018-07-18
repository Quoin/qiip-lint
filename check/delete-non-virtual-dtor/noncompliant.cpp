/**
 * @file Test for delete with non-virtual destructor warinings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Low      | Likely     | Low              | P9       | L2    |
 * 
 * @see SEI CERT C Coding Standard: Rule ARR30-C. Do not delete a polymorphic
 * object without a virtual destructor
 * https://wiki.sei.cmu.edu/confluence/display/cplusplus/OOP52-CPP.+Do+not+delete+a+polymorphic+object+without+a+virtual+destructor
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

struct Base
  {
    virtual void f();
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
    return 0;
  }