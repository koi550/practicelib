add_library(mytabmodel STATIC
    tablemodel.cpp
    itablereader.cpp
    jsontablereader.cpp
    tableproxymodel.cpp
)

target_include_directories(mytabmodel
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(mytabmodel
    PUBLIC
        Qt6::Core
)
