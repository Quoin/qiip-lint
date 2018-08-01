/**
 * @file Test for reorder warnings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Medium   | Unlikely   | Medium           | P4       | L3    |
 * 
 * @see SEI CERT C Coding Standard: Rule OOP53-CPP. Write constructor
 *   member initializers in the canonical order
 *   https://wiki.sei.cmu.edu/confluence/display/cplusplus/OOP53-CPP.+Write+constructor+member+initializers+in+the+canonical+order
 * 
 */

#include <cstdlib>


/**
 * Main entry point to program.
 */
signed main(void);


/**
 * Test warning when the order of member initializers givern in the code 
 * does not match the order in which they must be executed.
 */
static void qiip_reorder_test(void);


static void qiip_reorder_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    class C
      {
        int dependsOnSomeVal;
        int someVal;

    public:
        C(int val) : someVal(val), dependsOnSomeVal(someVal + 1) {}
      };

#else
    class C
      {
        int someVal;
        int dependsOnSomeVal;
    

    public:
        C(int val) : someVal(val), dependsOnSomeVal(someVal + 1) {}
      };

#endif
  }


signed main()
  {
    signed const result = EXIT_SUCCESS;
    qiip_reorder_test();
    return result;
  }
