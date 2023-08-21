cmake_minimum_required(VERSION 3.26)
project(SimpleDrawing)

set (PROJECT_SOURCE_FILES
    resource.h
    Shape2D.cpp
    Shape2D.h
    SimpleDrawing.rc
    main.cpp
)
# define project's build target with project's source files
add_executable(${PROJECT_NAME} WIN32 ${PROJECT_SOURCE_FILES})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)