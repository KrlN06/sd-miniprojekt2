file(GLOB PROJEKT_2_ROOT_SOURCES CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/*.cpp"
)

file(GLOB PROJEKT_2_ROOT_HEADERS CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/*.h"
)

file(GLOB_RECURSE PROJEKT_2_SOURCES CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/include/*.cpp"
)

file(GLOB_RECURSE PROJEKT_2_HEADERS CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/src/*.h"
    "${PROJECT_SOURCE_DIR}/include/*.h"
)

list(APPEND PROJEKT_2_SOURCES ${PROJEKT_2_ROOT_SOURCES})
list(APPEND PROJEKT_2_HEADERS ${PROJEKT_2_ROOT_HEADERS})

if(NOT PROJEKT_2_SOURCES)
    message(FATAL_ERROR "No C++ source files found in the project.")
endif()

add_executable(${PROJECT_NAME}
    ${PROJEKT_2_SOURCES}
    ${PROJEKT_2_HEADERS}
        ../include/DynamicArray.h
        BinaryHeapPriorityQueue.cpp
        ../include/BinaryHeapPriorityQueue.h
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${PROJECT_SOURCE_DIR}/include"
)

source_group(TREE "${PROJECT_SOURCE_DIR}" FILES
    ${PROJEKT_2_SOURCES}
    ${PROJEKT_2_HEADERS}
)
