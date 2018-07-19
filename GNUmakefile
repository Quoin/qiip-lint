###
 # Compiler.
 ##
CC ::= gcc-6

###
 # Preprocessor options.
 #
 # @note -W'no-system-headers' must be last.
 #
CPPFLAGS ::=\
  -D'QIIP_FIX=0'\
  -x'c' -std='c11' -O'3' -D'_FORTIFY_SOURCE=2'\
  @tool/gcc-6/warning-dialect-common.opt\
  @tool/gcc-6/warning-dialect-c.opt\
  @tool/gcc-6/warning-common.opt\
  @tool/gcc-6/warning-c.opt\
  -W'no-system-headers'
