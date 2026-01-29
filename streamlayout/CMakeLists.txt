add_library(streamlayout STATIC
    streamlayout.cpp
)

target_include_directories(streamlayout
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(streamlayout
    PUBLIC
        Qt6::Core
)
