cmake_minimum_required(VERSION 3.16)
project(HuffmanTree)

set(CMAKE_C_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -g")
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} ")

include_directories(include)

link_libraries(m)

file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)       #设置可执行文件的输出目录

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)           #设置库文件的输出目录




add_library(Base src/BuildTree.c src/Fileread.c src/Frequence_Count.c)

#target_compile_definitions(mv PRIVATE DOT_AVX2_CAN )


add_executable(zip src/zip.c)

target_link_libraries(zip Base)

add_executable(unzip src/unzip.c)

target_link_libraries(unzip Base)


