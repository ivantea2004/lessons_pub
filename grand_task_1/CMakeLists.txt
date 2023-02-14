cmake_minimum_required(VERSION 3.20)

project(grand_task_1)

FILE(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB src ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

add_executable(run ${src} ${headers})

target_compile_features(run PUBLIC c_std_99)

if(NOT TEST_TYPE)
	set(TEST_TYPE "TEST_64")
endif()

target_compile_definitions(run PUBLIC TEST_TYPE=${TEST_TYPE})
