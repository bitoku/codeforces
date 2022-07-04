cmake_minimum_required(VERSION 3.17)
project(codeforces)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE files "*.cpp")
list(FILTER files EXCLUDE REGEX "cmake-build-debug/.*")
foreach(file ${files})
    get_filename_component(output ${file} NAME_WE)
    add_executable(${output} ${file})
endforeach()