INCLUDE_DIRECTORIES(../include/)

SET(COMMONS_SRC ${COMMONS_SRC}
  memory/arrayAllocator.cpp
  memory/arrayMetaData.cpp
  memory/arrayObject.cpp
  memory/growthByNextPowerOfTwo.cpp
)

ADD_LIBRARY(COMMONS ${COMMONS_SRC})

TARGET_LINK_LIBRARIES(COMMONS ${Boost_LIBRARIES} )

INSTALL(TARGETS COMMONS
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )

