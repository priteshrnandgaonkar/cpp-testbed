cmake_minimum_required (VERSION 2.6)
project(type-deduction CXX)
set(PACKAGE_NAME, typededuction)
set(TYPEDEDUCTION_DIR, ${PROJECT_SOURCE_DIR}/type-deduction)

file(GLOB SRC_FILES ${TYPEDEDUCTION_DIR}/*.cpp)
add_library(${PACKAGE_NAME} STATIC ${SRC_FILES})
