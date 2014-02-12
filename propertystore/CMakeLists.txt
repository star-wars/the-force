# The name of the project is "C4".  CMakeLists files in this project can
# refer to the root source directory of the project as ${C4_SOURCE_DIR} and
# to the root binary directory of the project as ${C4_BINARY_DIR}.
PROJECT(C4)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

###BOOST
FIND_PACKAGE(Boost)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

INCLUDE(CheckIncludeFiles)
INCLUDE(CheckFunctionExists)
INCLUDE(CheckTypeSize)
INCLUDE(CTest)
INCLUDE(InstallRequiredSystemLibraries)

ENABLE_TESTING()

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -pthread")
endif()

SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "1")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
SET(CPACK_PACKAGE_VENDOR "Henning Rauch")
SET(CPACK_RESOURCE_FILE_LICENSE LICENSE.txt)

IF(CPack_CMake_INCLUDED)
ELSE(CPack_CMake_INCLUDED)
  INCLUDE(CPack)
  SET(CPack_CMake_INCLUDED 1)
ENDIF(CPack_CMake_INCLUDED)

ADD_SUBDIRECTORY(doxygen)

ADD_SUBDIRECTORY(Dependencies)
INCLUDE_DIRECTORIES (${ZETER_SOURCE_DIR}/include)
LINK_DIRECTORIES(${ZETER_BINARY_DIR})

ADD_SUBDIRECTORY(src build-src)
ADD_SUBDIRECTORY(tests build-tests)
ADD_SUBDIRECTORY(include build-include)