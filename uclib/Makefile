#
# This Makefile is not intended to be used directly by typing 'make' in this
# directory.
#
# It is used from within a project directory and the library is build into
# project local directory. The library parameters are propagated via following
# variables:
#
# MCU         - exact MCU type such as atmega8
#
# MCU_ARCH    - MCU architecture such as avr
#
# LIBDIR      - (possibly relative) path to library directory (i.e. to '../')
#
# LIBBUILDDIR - name of directory to build the library to
#

ifndef MCU
$(error MCU not set)
endif

ifndef MCU_ARCH
$(error MCU_ARCH not set)
endif

ifndef LIBDIR
$(error LIBDIR not set)
endif

ifndef LIBBUILDDIR
$(error LIBBBUILDDIR not set)
endif

SUBDIRS=src
CURSUBDIR=uClib

include subdirs.mk
