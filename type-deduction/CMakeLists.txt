cmake_minimum_required (VERSION 3.6.0)
project(type-deduction CXX)
set(TYPEDEDUCTION_DIR, ${PROJECT_SOURCE_DIR}/type-deduction)

file(GLOB SRC_FILES ${TYPEDEDUCTION_DIR}/*.cpp)
add_library(type-deduction STATIC ${SRC_FILES})
