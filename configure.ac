# Ref: https://earthly.dev/blog/autoconf/
# AC_INIT to name application, version an maintainer
AC_INIT([data-structure-and-algorithms], [0.1], [charles.low@pm.me])
# init automake to use together with autoconf
AM_INIT_AUTOMAKE
# specify compiler
AC_PROG_CC

# tell autoconf to find Makefile.in and replace placeholders accordingly
AC_CONFIG_FILES([Makefile])

# according to automake standard, source code should put into src/ folder 
# if you need to put c file in root folder you need the following
#AUTOMAKE_OPTIONS = foreign

# specify name of the binary compiled
bin_PROGRAMS = linkedlist
datastructure_SOURCES = src/linkedlist/main.c

# output the final configure script
AC_OUTPUT