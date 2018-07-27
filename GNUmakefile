#!/usr/bin/env make
#
# GNU Make build script.
#
# This uses the following environment variables to control the compilation:
#
# - QIIP_FIX set to 1 to compile "fixed" version of all test programs.


.POSIX :
.ONESHELL :
.SECONDEXPANSION :
.SECONDARY :


QIIP_FIX ?= 0


###
 # C compiler.
 ##
CC ::= gcc-6

###
 # C++ compiler.
 ##
CXX ::= g++-6


TARGET_ARCH ::= -m'64' -m'tune=native'

CFLAGS ::=\
  -pipe\
  -f'visibility=hidden'\
  -f'lto'\
  -f'pie'

LDFLAGS ::=\
  -pie\
  -f'use-ld=gold'\
  -Wl',--threads'\
  -Wl',-optimize,1'\
  -Wl',--gc-sections'\
  -Wl',--icf,safe'\
  -Wl',--build-id=sha1'\
  -Wl',--as-needed'\
  -Wl',--no-allow-multiple-definition'\
  -Wl',--error-unresolved-symbols'\
  -Wl',--no-undefined'\
  -Wl',--no-allow-shlib-undefined'
  -Wl',--unresolved-symbols=report-all'\
  -Wl',--warn-common'\
  -Wl',--detect-odr-violations'\
  -Wl',--warn-execstack'\
  -Wl',-z,nodelete'\
  -Wl',-z,nodlopen'\
  -Wl',-z,nodump'\
  -Wl',-z,noexecstack'\
  -Wl',-z,now'\
  -Wl',-z,relro'\
  -Wl',-z,text'


###
 # Compile command for compiling C as C++.
 ##
COMPILE.c.cxx = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c


qiip_check_c_srcs ::= $(wildcard check/*/*.c)
qiip_check_cxx_srcs ::= $(wildcard check/*/*.cpp)

qiip_check_c_objs ::= $(patsubst %.c,build/%.c.o,$(qiip_check_c_srcs))
qiip_check_c_cxx_objs ::= $(patsubst %.c,build/%.c.cxx.o,$(qiip_check_c_srcs))
qiip_check_cxx_objs ::= $(patsubst %.cpp,build/%.cxx.o,$(qiip_check_cxx_srcs))


qiip_check_c_bins ::= $(patsubst %.c,build/%.c.bin,$(qiip_check_c_srcs))
qiip_check_c_cxx_bins ::= $(patsubst %.c,build/%.c.cxx.bin,$(qiip_check_c_srcs))
qiip_check_cxx_bins ::= $(patsubst %.cpp,build/%.cxx.bin,$(qiip_check_cxx_srcs))


.PHONY : all
all : $(qiip_check_c_bins) $(qiip_check_c_cxx_bins) $(qiip_check_cxx_bins)

.PHONY : clean
clean :
	$(RM) -r -f 'build/'


###
 # Preprocessor options for C.
 #
 # @note -W'no-system-headers' must be last.
 ##
build/check/%.c.o : CPPFLAGS ::=\
  -D'QIIP_FIX=$(QIIP_FIX)'\
  -x'c' -std='c11' -O'3' -D'_FORTIFY_SOURCE=2'\
  -f'message-length=0' -f'no-diagnostics-color' -f'no-diagnostics-show-caret'\
  @tool/gcc-6/warning-dialect-common.opt\
  @tool/gcc-6/warning-dialect-c.opt\
  @tool/gcc-6/warning-common.opt\
  @tool/gcc-6/warning-c.opt\
  -W'no-system-headers'

###
 # Preprocessor options for C compiled as C++.
 #
 # @note -W'no-system-headers' must be last.
 ##
build/check/%.c.cxx.o : CPPFLAGS ::=\
  -D'QIIP_FIX=$(QIIP_FIX)'\
  -x'c++' -std='c++17' -O'3' -D'_FORTIFY_SOURCE=2' -D'_GLIBCXX_CONCEPT_CHECKS=1' -D'_GLIBCXX_ASSERTIONS=1'\
  -f'message-length=0' -f'no-diagnostics-color' -f'no-diagnostics-show-caret'\
  @tool/gcc-6/warning-dialect-common.opt\
  @tool/gcc-6/warning-dialect-c-cxx.opt\
  @tool/gcc-6/warning-common.opt\
  @tool/gcc-6/warning-cxx.opt\
  -W'no-system-headers'

###
 # Preprocessor options for C++.
 #
 # @note -W'no-system-headers' must be last.
 ##
build/check/%.cxx.o : CPPFLAGS ::=\
  -D'QIIP_FIX=$(QIIP_FIX)'\
  -x'c++' -std='c++17' -O'3' -D'_FORTIFY_SOURCE=2' -D'_GLIBCXX_CONCEPT_CHECKS=1' -D'_GLIBCXX_ASSERTIONS=1'\
  -f'message-length=0' -f'no-diagnostics-color' -f'no-diagnostics-show-caret'\
  @tool/gcc-6/warning-dialect-common.opt\
  @tool/gcc-6/warning-dialect-cxx.opt\
  @tool/gcc-6/warning-common.opt\
  @tool/gcc-6/warning-cxx.opt\
  -W'no-system-headers'


build/check/%.c.bin : build/check/%.c.o
	$(LINK.c) $(^) $(LOADLIBES) $(LDLIBS) -o '$(@)'

build/check/%.c.cxx.bin : build/check/%.c.cxx.o
	$(LINK.cc) $(^) $(LOADLIBES) $(LDLIBS) -o '$(@)'

build/check/%.cxx.bin : build/check/%.cxx.o
	$(LINK.cc) $(^) $(LOADLIBES) $(LDLIBS) -o '$(@)'


build/check/%.c.o : check/%.c | $${@D}/
	$(COMPILE.c) $(OUTPUT_OPTION) '${<}'

build/check/%.c.cxx.o : check/%.c | $${@D}/
	$(COMPILE.c.cxx) $(OUTPUT_OPTION) '${<}'

build/check/%.cxx.o : check/%.cpp | $${@D}/
	$(COMPILE.cc) $(OUTPUT_OPTION) '${<}'

%/ :
	mkdir -p '${@}'
