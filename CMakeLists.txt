cmake_minimum_required (VERSION 3.6.0)
set(PACKAGE_NAME cpp-testbed)
project(cpp-testbed)
set(BUILD_DIR ${PROJECT_SOURCE_DIR}/build)
set(TYPEDEDUCTION_LIB_NAME type-deduction)

message(STATUS ${BUILD_DIR})
file(MAKE_DIRECTORY ${BUILD_DIR})

set(TYPEDEDUCTION_DIR ${PROJECT_SOURCE_DIR}/type-deduction)
set(LIB_TYPEDEDUCTION_DIR ${BUILD_DIR}/type-deduction)

add_executable(${PACKAGE_NAME} main.cpp)

add_subdirectory(${TYPEDEDUCTION_DIR} ${LIB_TYPEDEDUCTION_DIR})

target_include_directories(${PACKAGE_NAME} PRIVATE
    ${TYPEDEDUCTION_DIR}/include)

target_link_libraries(${PACKAGE_NAME} ${TYPEDEDUCTION_LIB_NAME})
