# - Try to find qTestable
# Once done this will define
#
#  QTESTABLE_FOUND - System has qTestable
#  QTESTABLE_INCLUDE_DIR - The qTestable include directory
#  QTESTABLE_LIBRARIES - The libraries needed to use qTestable
#  QTESTABLE_DEFINITIONS - Compiler switches required for using qTestable

#=============================================================================
# Copyright 2006-2009 Kitware, Inc.
# Copyright 2006 Alexander Neundorf <neundorf@kde.org>
# Copyright 2011 Tejas Dinkar <tejas@gja.in>
#
# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
# (To distributed this file outside of CMake, substitute the full
#  License text for the above reference.)

IF (QTESTABLE_INCLUDE_DIR AND QTESTABLE_LIBRARIES)
   # in cache already
   SET(qTestable_FIND_QUIETLY TRUE)
ENDIF (QTESTABLE_INCLUDE_DIR AND QTESTABLE_LIBRARIES)

IF (NOT WIN32)
   # use pkg-config to get the directories and then use these values
   # in the FIND_PATH() and FIND_LIBRARY() calls
   FIND_PACKAGE(PkgConfig)
   PKG_CHECK_MODULES(PC_QTESTABLE qTestable)
   SET(QTESTABLE_DEFINITIONS ${PC_QTESTABLE_CFLAGS_OTHER})
ENDIF (NOT WIN32)

FIND_PATH(QTESTABLE_INCLUDE_DIR QTestable.h
   HINTS
   ${PC_QTESTABLE_INCLUDEDIR}
   ${PC_QTESTABLE_INCLUDE_DIRS}
   PATH_SUFFIXES libqTestable
   )

FIND_LIBRARY(QTESTABLE_LIBRARIES NAMES qTestable libqTestable
   HINTS
   ${PC_QTESTABLE_LIBDIR}
   ${PC_QTESTABLE_LIBRARY_DIRS}
   )

INCLUDE(FindPackageHandleStandardArgs)

# handle the QUIETLY and REQUIRED arguments and set QTESTABLE_FOUND to TRUE if 
# all listed variables are TRUE
FIND_PACKAGE_HANDLE_STANDARD_ARGS(qTestable DEFAULT_MSG QTESTABLE_LIBRARIES QTESTABLE_INCLUDE_DIR)

MARK_AS_ADVANCED(QTESTABLE_INCLUDE_DIR QTESTABLE_LIBRARIES)

