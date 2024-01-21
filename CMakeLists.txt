cmake_minimum_required(VERSION 3.20)

project(gulyakina-a-v-23-18)

set(CMAKE_CXX_STANDARD 20)

option(BUILD_WITH_CODEFORCES "Build prj.codeforces targets" off)

if (BUILD_WITH_CODEFORCES)
  add_subdirectory(prj.codeforces)
endif()

add_subdirectory(prj.lab) 
add_subdirectory(prj.test)
