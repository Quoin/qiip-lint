/**
 * @file Test for zero as null pointer warnings.
 *
 * @par Risk Assessment
 *
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Low      | Medium     | High             | P2       | L3    |
 *
 * @see SEI CERT C Coding Standard: Rule INT36-C. Converting a pointer
 *   to integer or integer to pointer
 *   https://wiki.sei.cmu.edu/confluence/display/c/INT36-C.+Converting+a+pointer+to+integer+or+integer+to+pointer
 */


#include <exception>
#include <cstdio>
#include <cstdlib>


/**
 * Main entry point to program.
 */
auto main [[gnu::nothrow]] (void) -> signed;


namespace qiip
  {
    /**
     * Test warning when using '0' as null pointer.
     */
    static auto zeroasnullpointer_test [[gnu::nothrow]] (void) -> void;
  }


static auto qiip::zeroasnullpointer_test(void) -> void
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    char const * const __restrict__ string{0};
#else
    char const * const __restrict__ string{nullptr};
#endif
    std::printf("string=\"%p\".\n", string);
  }


auto main(void) -> signed
  {
    auto result{EXIT_SUCCESS};

    try
      {
        qiip::zeroasnullpointer_test();
      }
    catch (std::exception const & __restrict__ e)
      {
        auto const msg{e.what()};
        std::fprintf
          (
            stderr, "Failure executing tests. exception=\"%s\".\n", msg
          );
        result = EXIT_FAILURE;
      }
    catch (...)
      {
        std::fprintf(stderr, "Failure executing tests. Unknown exception.\n");
        result = EXIT_FAILURE;
      }

    return result;
  }
