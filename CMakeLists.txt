cmake_minimum_required(VERSION 3.17)
project(Matrix_Determinant C)

set(CMAKE_C_STANDARD 99)

set(SOURCES
        Sources/interact.c
        Sources/file.c
        Sources/calculus.c
)

set(HEADERS
        Headers/inform.h
)

set(OBJECTS

)

add_executable(Matrix_Determinant main.c ${SOURCES} ${HEADERS} ${OBJECTS})
target_link_libraries(Matrix_Determinant -lm)