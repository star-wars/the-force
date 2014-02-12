MACRO(C4_TEST name)
        ADD_EXECUTABLE(${name} ${name}.cxx)
        TARGET_LINK_LIBRARIES(${name}  C4)
        ADD_TEST(${name} ${name})
ENDMACRO(C4_TEST name)

INCLUDE_DIRECTORIES(../include/)
INCLUDE_DIRECTORIES(../src/)

C4_TEST(t_c4_basic)
