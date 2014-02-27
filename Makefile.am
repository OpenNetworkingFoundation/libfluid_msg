AUTOMAKE_OPTIONS = subdir-objects
# For using custom m4 macros.
ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = README.md

AM_CPPFLAGS = \
  -I$(top_srcdir)/fluid

# Build rules for testing framework.
check_LTLIBRARIES = \
  test/lib/gmock/libgmock.la \
  test/lib/gmock/libgmock_main.la

test_lib_gmock_libgmock_la_SOURCES = \
  test/lib/gmock/gmock/gmock.h \
  test/lib/gmock/gtest/gtest.h \
  test/lib/gmock/gmock-gtest-all.cc
test_lib_gmock_libgmock_la_CPPFLAGS = $(GTEST_CPPFLAGS)
test_lib_gmock_libgmock_la_CXXFLAGS = $(GTEST_CXXFLAGS)
test_lib_gmock_libgmock_la_LDFLAGS = $(GTEST_LDFLAGS)
test_lib_gmock_libgmock_la_LIBADD = $(GTEST_LIBS)

test_lib_gmock_libgmock_main_la_SOURCES = \
  test/lib/gmock/gmock/gmock.h \
  test/lib/gmock/gtest/gtest.h \
  test/lib/gmock/gmock_main.cc
test_lib_gmock_libgmock_main_la_CPPFLAGS = $(GTEST_CPPFLAGS)
test_lib_gmock_libgmock_main_la_CXXFLAGS = $(GTEST_CXXFLAGS)
test_lib_gmock_libgmock_main_la_LDFLAGS = $(GTEST_LDFLAGS)
test_lib_gmock_libgmock_main_la_LIBADD = \
  $(GTEST_LIBS) \
  test/lib/gmock/libgmock.la

# Build rules for libraries.
libfluid_msg_includedir = $(includedir)
nobase_libfluid_msg_include_HEADERS = \
                   fluid/ofcommon/msg.hh \
                   fluid/ofcommon/action.hh \
                   fluid/ofcommon/common.hh \
                   fluid/ofcommon/openflow-common.hh \
                   fluid/of10/of10action.hh \
                   fluid/of10/of10common.hh \
                   fluid/of10/of10match.hh \
                   fluid/of10/openflow-10.h\
                   fluid/of10msg.hh \
                   fluid/of13/of13instruction.hh\
                   fluid/of13/of13match.hh \
                   fluid/of13/of13meter.hh \
                   fluid/of13/of13action.hh \
                   fluid/of13/of13common.hh \
                   fluid/of13/openflow-13.h \
                   fluid/of13msg.hh \
                   fluid/util/ethaddr.hh \
                   fluid/util/ipaddr.hh \
                   fluid/util/util.h 

noinst_LTLIBRARIES = \
  fluid/util/libutil.la \
  fluid/ofcommon/libofcommon.la \
  fluid/of10/libof10.la \
  fluid/of13/libof13.la 

lib_LTLIBRARIES = \
  libfluid_msg.la

fluid_util_libutil_la_SOURCES = \
               fluid/util/ethaddr.hh fluid/util/ethaddr.cc \
               fluid/util/ipaddr.hh fluid/util/ipaddr.cc \
               fluid/util/util.h 

fluid_ofcommon_libofcommon_la_SOURCES =  \
               fluid/ofcommon/msg.hh fluid/ofcommon/msg.cc \
               fluid/ofcommon/action.hh fluid/ofcommon/action.cc \
               fluid/ofcommon/common.hh fluid/ofcommon/common.cc \
               fluid/ofcommon/openflow-common.hh  

fluid_of10_libof10_la_SOURCES = \
               fluid/of10/of10action.hh fluid/of10/of10action.cc \
               fluid/of10/of10common.hh fluid/of10/of10common.cc \
               fluid/of10/of10match.hh fluid/of10/of10match.cc \
               fluid/of10/openflow-10.h

fluid_of13_libof13_la_SOURCES = \
               fluid/of13/of13instruction.hh fluid/of13/of13instruction.cc \
               fluid/of13/of13action.hh fluid/of13/of13action.cc \
               fluid/of13/of13match.hh fluid/of13/of13match.cc \
               fluid/of13/of13meter.hh fluid/of13/of13meter.cc \
               fluid/of13/of13common.hh fluid/of13/of13common.cc \
               fluid/of13/openflow-13.h 

libfluid_msg_la_SOURCES = fluid/of10msg.hh fluid/of10msg.cc \
                          fluid/of13msg.hh fluid/of13msg.cc
libfluid_msg_la_LIBADD = $(top_builddir)/fluid/util/libutil.la \
                        $(top_builddir)/fluid/ofcommon/libofcommon.la \
                        $(top_builddir)/fluid/of10/libof10.la  \
                        $(top_builddir)/fluid/of13/libof13.la  

# Build rules for tests.
# TESTS_ENVIRONMENT: Set environment variables for the test run
# TESTS: Define programs run automatically by "make check"
# UNIT_TESTS: Define programs run automatically by "make check-unit-tests"
# check_PROGRAMS: Define programs built by "make check" but not necessarily run
TESTS_ENVIRONMENT=
TESTS=
UNIT_TESTS=
check_PROGRAMS=

# Define unit tests with gtest
UNIT_TESTS += test/fluid_msg_test
check_PROGRAMS += test/fluid_msg_test
test_fluid_msg_test_SOURCES = test/fluid_msg_test.cc test/version_test.cc \
                              test/basic_pack_unpack_test.cc test/stats_test.cc \
                              test/multipart_test.cc test/flow_mod.cc \
                              test/constants.hh 
test_fluid_msg_test_CPPFLAGS = -I$(top_srcdir)/fluid $(GTEST_CPPFLAGS)
test_fluid_msg_test_CXXFLAGS = $(GTEST_CXXFLAGS)
test_fluid_msg_test_LDFLAGS = $(GTEST_LDFLAGS)
test_fluid_msg_test_LDADD = $(top_builddir)/libfluid_msg.la \
                         $(GTEST_LIBS) \
                         $(top_builddir)/test/lib/gmock/libgmock_main.la \
                         $(top_builddir)/test/lib/gmock/libgmock.la

TESTS += $(UNIT_TESTS)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libfluid_msg.pc
