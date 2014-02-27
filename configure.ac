# Initialize Autoconf.
# Specify package's name, version number and bug-report address.
AC_INIT([libfluid_msg], [1.0], [ederlf@cpqd.com.br], [libfluid_msg], [http://www.cpqd.com.br/])

AC_PREREQ([2.59])
# For using custom m4 macros.
AC_CONFIG_MACRO_DIR([m4])

# Auxiliary scripts such as install-sh and depcomp should be in following directory.
AC_CONFIG_AUX_DIR([build-aux])

# Initialize Automake.
# There are useful options.
#   -Wall: Turn all warnings on.
#   foreign: ignores some GNU Coding Standards.
#   subdirs-objects: Create objects in sub-direcotories
AM_INIT_AUTOMAKE([1.10 no-define -Wall foreign subdir-objects])

# Initialize Libtool.
LT_INIT

# * Check for a C++ compiler.
AC_PROG_CXX

AC_LANG([C++], [C])

AC_PROG_LIBTOOL

# Check for libraries.
# * Check for pthreads library.
ACX_PTHREAD([have_pthread=yes], [heve_pthread=no])

# Define variables for unit test using gtest
GTEST_VERSION="1.6.0"
if test "x$have_pthread" = "xyes"; then
  GTEST_CPPFLAGS="-DGTEST_HAS_PTHREAD=1 -I\$(top_srcdir)/test/lib/gmock"
  GTEST_CXXFLAGS="$PTHREAD_CFLAGS"
  GTEST_LDFLAGS="-L\$(top_builddir)/test/lib/gmock"
  GTEST_LIBS="$PTHREAD_LIBS"
else
  GTEST_CPPFLAGS="-DGTEST_HAS_PTHREAD=0 -I\$(top_srcdir)/test/lib/gmock"
  GTEST_CXXFLAGS=
  GTEST_LDFLAGS="-L\$(top_builddir)/test/lib/gmock"
  GTEST_LIBS=
fi
AC_SUBST([GTEST_VERSION])
AC_SUBST([GTEST_CPPFLAGS])
AC_SUBST([GTEST_CXXFLAGS])
AC_SUBST([GTEST_LDFLAGS])
AC_SUBST([GTEST_LIBS])

# Check python for the script checking coding style
AC_CHECK_PROG(HAVE_PYTHON, python, yes, no)

# Check for C++11 supports
#   ext: use extended mode (e.g. -std=gnu++11)
#   noext: use non-extended mode (e.g. -std=c++11)
# AX_CXX_COMPILE_STDCXX_11([noext])

# Check for header files.

# Check for typedefs, structures, and compiler characteristics.

# Check for library functions.

# Check for the existance of a file in the source directory.
AC_CONFIG_SRCDIR([fluid/of10msg.hh])

AC_SUBST([LIBFLUID_MSG_SO_VERSION], [0:0:0])

# Output files.
# AC_CONFIG_HEADERS(HEADERS...)
# Create Header for all HEADER.in Use only one such header unless you know what you are doing.
# Declare config.h as output header.
AC_CONFIG_HEADERS([config.h])

# Declare output files.
AC_CONFIG_FILES([Makefile libfluid_msg.pc])

# Actually output all declared files.
AC_OUTPUT

AC_MSG_RESULT([
Configure Information:
  C Compiler        : $CC
    DEFS            :   $DEFS
    CPPFLAGS        :   $CPPFLAGS
    CFLAGS          :   $CFLAGS

  C++ Compiler      : $CXX
    DEFS            :   $DEFS
    CPPFLAGS        :   $CPPFLAGS
    CXXFLAGS        :   $CXXFLAGS

  Linker            : $LD
    LDFLAGS         :   $LDFLAGS
    LIBS            :   $LIBS

  Coding Style Checks   : $HAVE_PYTHON
])
