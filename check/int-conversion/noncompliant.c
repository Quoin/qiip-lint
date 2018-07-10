/**
 * @file Test for integer conversion warnings.
 */


#include <stdio.h>
#include <stdlib.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when assigning integer literal to a pointer.
 */
static void literal_test(void);

/**
 * Test warning when assigning integer variable to a pointer.
 */
static void variable_test(signed arg);


/**
 * Main entry point to program.
 */
signed main(void);


#ifdef __cplusplus
}
#endif


static void literal_test(void)
  {
#ifndef QIIP_FIX
    void const * const ptr = 1;
#else
    void const * const ptr = NULL;
#endif
  
    printf("ptr=\"%p\".\n", ptr);
  }


static void variable_test(signed const arg)
  {
#ifndef QIIP_FIX
    void const * const ptr = arg;
    printf("arg=\"%d\" ptr=\"%p\".\n", arg, ptr);
#else
    /* There is no good fix. Explicit conversion is a bad idea. */
    printf("arg=\"%d\".\n", arg);
#endif
  }


signed main(void)
  {
    literal_test();
    variable_test(10);
    return EXIT_SUCCESS;
  }
