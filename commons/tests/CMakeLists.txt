INCLUDE_DIRECTORIES(../include/)
INCLUDE_DIRECTORIES(../include/memory)
INCLUDE_DIRECTORIES(../include/synchronization)

MACRO(COMMONS_TEST name)
        ADD_EXECUTABLE(${name} ${name}.cxx)
        TARGET_LINK_LIBRARIES(${name} ${Boost_LIBRARIES} COMMONS)
        ADD_TEST(${name} ${name})
ENDMACRO(COMMONS_TEST name)

COMMONS_TEST(t_commons_lockableElement)
COMMONS_TEST(t_commons_objectPool)
