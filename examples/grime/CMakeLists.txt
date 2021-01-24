cmake_minimum_required(VERSION 3.7)


add_executable(grime ${CMAKE_CURRENT_SOURCE_DIR}/grime_example.cpp)
target_link_libraries(grime volt_math)
set_property(TARGET grime PROPERTY CXX_STANDARD 17)