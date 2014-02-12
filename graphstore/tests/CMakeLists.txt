MACRO(GRAPHSTORE_TEST name)
        ADD_EXECUTABLE(${name} ${name}.cxx)
        TARGET_LINK_LIBRARIES(${name}  GRAPHSTORE)
        ADD_TEST(${name} ${name})
ENDMACRO(GRAPHSTORE_TEST name)

INCLUDE_DIRECTORIES(../include/)

GRAPHSTORE_TEST(t_graphStore_basic)
