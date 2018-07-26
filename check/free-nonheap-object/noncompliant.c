/**
 * @file Test for free nonheap object warning (-W'free-nonheap-object').
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | High     | Likely     | Medium           | P18      | L1    |
 * 
 * @see SEI CERT C Coding Standard: Rule MEM34-C. Only free memory allocated
 *   dynamically
 *   https://wiki.sei.cmu.edu/confluence/display/c/MEM34-C.+Only+free+memory+allocated+dynamically
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>


/**
 * Main entry point to program.
 */
signed main(void) __attribute__((nothrow));


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Test warning when freeing non-heap objects.
 */
static void qiip_freenonheapobject_test(void) __attribute__((nothrow));

/**
 * Test warning when freeing non-heap objects with constant if statement.
 */
static void qiip_constantiffree_test(void);

/**
 * Test warning when freeing non-heap objects with variable is statement.
 */
static void qiip_variableiffree_test(void);

/**
 * Test warning when freeing double pointer that is non-heap.
 */
static void qiip_doublepointerfree_test(void);

/**
 * Test warning when freeing array of pointers that are non-heap.
 */
static void qiip_arrayofpointerfree_test(void);

/**
 * Test warning when freeing pointer to different data type.
 */
static void qiip_pointertypefree_test(void);


#ifdef __cplusplus
}
#endif

static void qiip_freenonheapobject_test(void)
  {
    char const msg[] = "hello, world";

#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    char string[sizeof msg] = "";
#else
    char * const __restrict__ string = (char *)malloc(sizeof msg);
#endif

    strcpy(string, msg);
    printf("string=\"%s\".\n", string);
    free(string);
  }


static void qiip_constantiffree_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    char* string="a";
	  if(1)
      {
        free(string);
      }
#else
    char const * const string = "a";
    printf("string=\"%s\".\n", string);
    /* Memory cleaned automatically. */
#endif
  }

static void qiip_variableiffree_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    char* string="a";
    signed temp = 1;
	  if(temp > 0)
      {
        free(string);
      }
#else
    char string[] = "a";
    free(string);
#endif
  }

static void qiip_doublepointerfree_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    char** string;
	  char *string1 = "STRING";
	  string = &string1;
	  free(string);
#else
    char* string1 = "a";
	  char** string = &string1;
	  while(0)
      {
        free(string);
      }
#endif
  }

static void qiip_arrayofpointerfree_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    char *arr1 = (char*) calloc(5, sizeof(char));
    char *arr2 = (char*) calloc(5, sizeof(char));
    char **parr[2] = {&arr1, &arr2};
    int i, j = 1;
    if(arr2 != NULL)
      {
        arr2[0] = 10.0;
      }
    for(i = 0; i < 2; i++)
      {
      *((*parr[i]) + j) = 5.0;
      }
    free(arr1);
    free(arr2);
    free(parr);
#else
    char *arr1 = (char*) calloc(5, sizeof(char));
    char *arr2 = (char*) calloc(5, sizeof(char));
    char **parr[2] = {&arr1, &arr2};
    int i, j = 1;
    if(arr2 != NULL)
      {
        arr2[0] = 10.0;
      }
    for(i = 0; i < 2; i++)
      {
      *((*parr[i]) + j) = 5.0;
      }
    free(arr1);
    free(arr2);
#endif
  }

static void qiip_pointertypefree_test(void)
  {
#if !((defined QIIP_FIX) && (1 == QIIP_FIX))
    int a = 2;
    double b = 4.5;
    char* string1="a";
    int* string2 = &a;
    double* string3 = &b;
    free(string3);
    printf("%s,%ls", string1, string2);
#else
    char* string1 = malloc(sizeof(char));
    int* string2 = malloc(sizeof(int));
    float* string3 = malloc(sizeof(float));
    double* string4 = malloc(sizeof(double));
    free(string1);
    free(string2);
    free(string3);
    free(string4);
#endif
  }

signed main(void)
  {
    signed const result = EXIT_SUCCESS;
    qiip_freenonheapobject_test();
    qiip_constantiffree_test();
    qiip_variableiffree_test();
    qiip_doublepointerfree_test();
    qiip_arrayofpointerfree_test();
    qiip_pointertypefree_test();
    return result;
  }
