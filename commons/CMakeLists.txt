PROJECT(COMMONS)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

### C++11 + threading
#list(APPEND CMAKE_CXX_FLAGS "-pthread -std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs -Wall")

###BOOST
FIND_PACKAGE(Boost COMPONENTS system thread REQUIRED)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

ADD_SUBDIRECTORY(doxygen)
ADD_SUBDIRECTORY(src build-src)
ADD_SUBDIRECTORY(tests build-tests)
ADD_SUBDIRECTORY(include build-include)
