# The name of the project is "PROPERTYSTORE".  CMakeLists files in this project can
# refer to the root source directory of the project as ${PROPERTYSTORE_SOURCE_DIR} and
# to the root binary directory of the project as ${PROPERTYSTORE_BINARY_DIR}.
PROJECT(PROPERTYSTORE)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

###BOOST
FIND_PACKAGE(Boost)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

ADD_SUBDIRECTORY(doxygen)

INCLUDE_DIRECTORIES (${COMMONS_SOURCE_DIR}/include)
LINK_DIRECTORIES(${COMMONS_BINARY_DIR})

ADD_SUBDIRECTORY(src build-src)
ADD_SUBDIRECTORY(tests build-tests)
ADD_SUBDIRECTORY(include build-include)
