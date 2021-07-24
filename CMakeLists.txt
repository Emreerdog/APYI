cmake_minimum_required(VERSION 3.16)
project(APYI)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
  message(STATUS "Build type not specified: Use Release by default")
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 17)

add_executable(APYI main.cpp)

find_package(Python COMPONENTS Interpreter Development)


message("Python_FOUND:${Python_FOUND}")
message("Python_VERSION:${Python_VERSION}")
message("Python_Development_FOUND:${Python_Development_FOUND}")
message("Python_LIBRARIES:${Python_LIBRARIES}")
message("Python_LIBRARIES:${Python_LIBRARY_DIRS}")
message("${Python_INCLUDE_DIRS}")

#find_package(Boost 1.74.0 REQUIRED)

include_directories(./source/ ${Python_INCLUDE_DIRS} "${PROJECT_SOURCE_DIR}/source/AdvancedPythonInterface/ThirdParty/include/")
 
add_subdirectory(source)

target_link_libraries(APYI PRIVATE apyi ${Python_LIBRARIES} "${PROJECT_SOURCE_DIR}/source/AdvancedPythonInterface/ThirdParty/lib/libjsoncpp.a")
target_include_directories(APYI PUBLIC "${PROJECT_SOURCE_DIR}/source/"  ${Python_INCLUDE_DIRS} "${PROJECT_SOURCE_DIR}/source/AdvancedPythonInterface/ThirdParty/include/")
