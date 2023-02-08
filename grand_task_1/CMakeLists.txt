cmake_minimum_required(VERSION 3.20)

project(grand_task_1)

add_executable(run main.c)

target_compile_features(run PUBLIC c_std_99)
