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
 */


#include <cstdio>
#include <cstdlib>


/**
 * Main entry point to program.
 */
auto main(void) -> signed;


namespace 
  {
    namespace qiip
      {
        class local
          {
            public:
              local(signed val);
              auto print(void) const -> void;

            private:
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
              signed depends_on_value;
              signed value;
#else
              signed value;
              signed depends_on_value;
#endif
          };


        /**
         * Test warning when the order of member initializers.
         *
         * This checks that the order declared in the class matches the order in
         * the constructor's member initializer list.
         */
        auto reorder_test(void) -> void;
      }
  }


auto main(void) -> signed
  {
    auto const result{EXIT_SUCCESS};
    qiip::reorder_test();
    return result;
  }


qiip::local::local(signed const val)
  :
    value{val},
    depends_on_value{this->value + 1}
  {
  }


auto qiip::local::print(void) const -> void
  {
    std::printf
      (
        "value=\"%d\" depends_on_value=\"%d\".\n",
        this->value, this->depends_on_value
      );
  }


auto qiip::reorder_test(void) -> void
  {
    qiip::local const obj{0};
    obj.print();
  }
