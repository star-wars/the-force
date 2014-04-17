PROJECT(THE-FORCE)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

###BOOST
FIND_PACKAGE(Boost COMPONENTS system thread REQUIRED)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

INCLUDE(CheckIncludeFiles)
INCLUDE(CheckFunctionExists)
INCLUDE(CheckTypeSize)
INCLUDE(CTest)
INCLUDE(InstallRequiredSystemLibraries)

ENABLE_TESTING()

### C++11 + threading
list(APPEND CMAKE_CXX_FLAGS "-pthread -std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs -Wall")

SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "2")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
SET(CPACK_PACKAGE_VENDOR "Henning Rauch")
SET(CPACK_RESOURCE_FILE_LICENSE ${THE-FORCE_SOURCE_DIR}/LICENSE.txt)

IF(CPack_CMake_INCLUDED)
ELSE(CPack_CMake_INCLUDED)
  INCLUDE(CPack)
  SET(CPack_CMake_INCLUDED 1)
ENDIF(CPack_CMake_INCLUDED)

ADD_SUBDIRECTORY(commons)
ADD_SUBDIRECTORY(propertyStore)
ADD_SUBDIRECTORY(graphStore)
ADD_SUBDIRECTORY(doxygen)

SET(THE-FORCE_SRC ${THE-FORCE_SRC}
  startup/the-force.cpp
)

# Make sure the compiler can find include files from the graphstore library.
INCLUDE_DIRECTORIES (${GRAPHSTORE_SOURCE_DIR}/include)
# Make sure the linker can find the graphstore library once it is built.
LINK_DIRECTORIES(${GRAPHSTORE_BINARY_DIR})

# Make sure the compiler can find include files from the propertystore library.
INCLUDE_DIRECTORIES (${PROPERTYSTORE_SOURCE_DIR}/include)
# Make sure the linker can find the propertystore library once it is built.
LINK_DIRECTORIES(${PROPERTYSTORE_BINARY_DIR})

# Make sure the compiler can find include files from the commons library.
INCLUDE_DIRECTORIES (${COMMONS_SOURCE_DIR}/include)
# Make sure the linker can find the commons library once it is built.
LINK_DIRECTORIES(${COMMONS_BINARY_DIR})

# Add executable called "the-force" that is built from the source files
ADD_EXECUTABLE(the-force ${THE-FORCE_SRC})

# Link the executable to the libraries.
TARGET_LINK_LIBRARIES(the-force COMMONS PROPERTYSTORE GRAPHSTORE)

INSTALL(TARGETS the-force
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
