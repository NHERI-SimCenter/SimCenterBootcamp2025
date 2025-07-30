cmake_minimum_required (VERSION 2.6)

project (matMUL)

find_package(BLAS REQUIRED)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(binaryMatMul binaryMatMul.c myDGEMM_Pointers.c blasDGEMM.c)
target_link_libraries(binaryMatMul m)
target_link_libraries(binaryMatMul ${BLAS_LIBRARIES})



