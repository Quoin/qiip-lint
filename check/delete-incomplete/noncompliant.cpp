/**
 * @file Test for delete incomplete warnings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Medium   | Unlikely   | Medium           | P4       | L3    |
 * 
 * @see SEI CERT C Coding Standard: Rule ARR30-C. Do not cast or delete
 *   pointers to incomplete classes
 *   https://wiki.sei.cmu.edu/confluence/display/cplusplus/EXP57-CPP.+Do+not+cast+or+delete+pointers+to+incomplete+classes
 * 
 */


#include <memory>
#include <cstdio>
#include <cstdlib>
#include <cstddef>


/**
 * Test warning when deleting pointer to incomplete classes.
 */
static void qiip_deleteincomplete_test(void);

/**
 * Main entry point to program.
 */
signed main(void);


static void qiip_deleteincomplete_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    class Handle
      {
        class Body *impl; // Declaration of a pointer to an incomplete class
    public:
        ~Handle() { delete impl; } // Deletion of pointer to an incomplete class
                                   // ...
      };
#else
    class Handle 
      {
        std::shared_ptr<class Body> impl;
        public:
            Handle();
            ~Handle() {}
      };
#endif

    printf("I'm really doing something.\n");
  }


signed main(void)
  {
    signed const result = EXIT_SUCCESS;
    qiip_deleteincomplete_test();
    return result;
  }
