INCLUDE_DIRECTORIES(../include/)
INCLUDE_DIRECTORIES(../include/model/)
INCLUDE_DIRECTORIES(../include/manager/)

SET(PATH_SRC ${PATH_SRC}
  pathDb.cpp
  manager/transactionManager.cpp
  model/graphElement.cpp
  model/edge.cpp
  model/vertex.cpp
  model/edgeContainer.cpp
)

ADD_LIBRARY(PATH ${PATH_SRC})
TARGET_LINK_LIBRARIES(PATH C4 ZETER)

INSTALL(TARGETS PATH
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )

