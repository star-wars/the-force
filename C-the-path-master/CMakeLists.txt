PROJECT(C-THE-PATH)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

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

ADD_SUBDIRECTORY(Dependencies)

SET(CTP_SRC ${CTP_SRC}
  src/demo.cxx
)

ADD_SUBDIRECTORY(doxygen)

# Make sure the compiler can find include files from the F8 library.
INCLUDE_DIRECTORIES (${PATH_SOURCE_DIR}/include)
# Make sure the linker can find the F8 library once it is built.
LINK_DIRECTORIES(${PATH_BINARY_DIR})

# Make sure the compiler can find include files from the C4 library.
INCLUDE_DIRECTORIES (${C4_SOURCE_DIR}/include)
# Make sure the linker can find the C4 library once it is built.
LINK_DIRECTORIES(${C4_BINARY_DIR})

# Make sure the compiler can find include files from the Zeter library.
INCLUDE_DIRECTORIES (${ZETER_SOURCE_DIR}/include)
# Make sure the linker can find the Zeter library once it is built.
LINK_DIRECTORIES(${ZETER_BINARY_DIR})

# Add executable called "ctp" that is built from the source files
# "demo.cxx" and "demo_b.cxx".  The extensions are automatically found.
ADD_EXECUTABLE(ctp ${CTP_SRC})

# Link the executable to the F8 library.
TARGET_LINK_LIBRARIES(ctp ZETER PATH C4)

INSTALL(TARGETS ctp
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
