.POSIX :
.ONESHELL :
.SECONDEXPANSION :
.SECONDARY :

###
 # Compiler.
 ##
CC ::= gcc-6

###
 # Compiler.
 ##
CXX ::= g++-6

###
 # Compile command for compiling C as C++.
 ##
COMPILE.c.cxx = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c


qiip_check_c_srcs ::= $(wildcard check/*/*.c)
qiip_check_cxx_srcs ::= $(wildcard check/*/*.cpp)

qiip_check_c_objs ::= $(patsubst %.c,build/%.c.o,$(qiip_check_c_srcs))
qiip_check_c_cxx_objs ::= $(patsubst %.c,build/%.c.cxx.o,$(qiip_check_c_srcs))
qiip_check_cxx_objs ::= $(patsubst %.cpp,build/%.cxx.o,$(qiip_check_cxx_srcs))


.PHONY : all
all : $(qiip_check_c_objs) $(qiip_check_c_cxx_objs) $(qiip_check_cxx_objs)

.PHONY : clean
clean :
	$(RM) -r -f 'build/'


###
 # Preprocessor options for C.
 #
 # @note -W'no-system-headers' must be last.
 #
build/check/%.c.o : CPPFLAGS ::=\
  -D'QIIP_FIX=0'\
  -x'c' -std='c11' -O'3' -D'_FORTIFY_SOURCE=2'\
  @tool/gcc-6/warning-dialect-common.opt\
  @tool/gcc-6/warning-dialect-c.opt\
  @tool/gcc-6/warning-common.opt\
  @tool/gcc-6/warning-c.opt\
  -W'no-system-headers'

###
 # Preprocessor options for C compiled as C++.
 #
 # @note -W'no-system-headers' must be last.
 #
build/check/%.c.cxx.o : CPPFLAGS ::=\
  -D'QIIP_FIX=0'\
  -x'c++' -std='c++17' -O'3' -D'_FORTIFY_SOURCE=2' -D'_GLIBCXX_CONCEPT_CHECKS=1' -D'_GLIBCXX_ASSERTIONS=1'\
  @tool/gcc-6/warning-dialect-common.opt\
  @tool/gcc-6/warning-dialect-c-cxx.opt\
  @tool/gcc-6/warning-common.opt\
  @tool/gcc-6/warning-cxx.opt\
  -W'no-system-headers'

###
 # Preprocessor options for C++.
 #
 # @note -W'no-system-headers' must be last.
 #
build/check/%.cxx.o : CPPFLAGS ::=\
  -D'QIIP_FIX=0'\
  -x'c++' -std='c++17' -O'3' -D'_FORTIFY_SOURCE=2' -D'_GLIBCXX_CONCEPT_CHECKS=1' -D'_GLIBCXX_ASSERTIONS=1'\
  @tool/gcc-6/warning-dialect-common.opt\
  @tool/gcc-6/warning-dialect-cxx.opt\
  @tool/gcc-6/warning-common.opt\
  @tool/gcc-6/warning-cxx.opt\
  -W'no-system-headers'


build/check/%.c.o : check/%.c | $${@D}/
	$(COMPILE.c) $(OUTPUT_OPTION) '${<}'

build/check/%.c.cxx.o : check/%.c | $${@D}/
	$(COMPILE.c.cxx) $(OUTPUT_OPTION) '${<}'

build/check/%.cxx.o : check/%.cpp | $${@D}/
	$(COMPILE.cc) $(OUTPUT_OPTION) '${<}'

%/ :
	mkdir -p '${@}'
