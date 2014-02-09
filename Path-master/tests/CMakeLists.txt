MACRO(PATH_TEST name)
        ADD_EXECUTABLE(${name} ${name}.cxx)
        TARGET_LINK_LIBRARIES(${name}  PATH)
        ADD_TEST(${name} ${name})
ENDMACRO(PATH_TEST name)

INCLUDE_DIRECTORIES(../include/)

PATH_TEST(t_path_basic)
