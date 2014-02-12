INCLUDE_DIRECTORIES(../include/)
INCLUDE_DIRECTORIES(../include/model/)
INCLUDE_DIRECTORIES(../include/manager/)

SET(GRAPHSTORE_SRC ${GRAPHSTORE_SRC}
  graphStore.cpp
  manager/transactionManager.cpp
  model/graphElement.cpp
  model/edge.cpp
  model/vertex.cpp
  model/edgeContainer.cpp
)

ADD_LIBRARY(GRAPHSTORE ${GRAPHSTORE_SRC})
TARGET_LINK_LIBRARIES(GRAPHSTORE PROPERTYSTORE COMMONS)

INSTALL(TARGETS GRAPHSTORE
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )

