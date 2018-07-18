/**
 * @file Test for implicit function declaration warinings.
 * 
 * @par Risk Assessment
 * 
 * | Severity | Likelihood | Remediation Cost | Priority | Level |
 * | -------- | ---------- | ---------------- | -------- | ----- |
 * | Low      | Unlikely   | Low              | P3       | L3    |
 * 
 * @see SEI CERT C Coding Standard: Rule DCL31-C. Declare identifiers before
 * using them
 * https://wiki.sei.cmu.edu/confluence/display/c/ARR30-C.+Do+not+form+or+use+out-of-bounds+pointers+or+array+subscripts
 * 
 */



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



signed main()
  {
    char* string = (char*) malloc(sizeof(char));
    free(string);
  }