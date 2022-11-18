cmake_minimum_required(VERSION 3.16)
project(scratchpad LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(third_party/level-zero)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
#find_package(GTest REQUIRED)
find_package(IntelSYCL_level_zero REQUIRED)

add_executable(make_device_test
  make_device_test.cpp)
target_compile_options(make_device_test PUBLIC -frtti -fexceptions)
target_link_libraries(make_device_test
  #GTest::gtest
  #GTest::gtest_main
  Intel::SYCL_level_zero
  ze_loader
  ${CMAKE_DL_LIBS})
target_include_directories(make_device_test
  PRIVATE third_party/level-zero/include)

