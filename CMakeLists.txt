cmake_minimum_required(VERSION 3.12.4)

if($ENV{TRAVIS_BUILD_NUMBER})
  set(VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
  set(VERSION 0.0.0)
endif()
project(kkmeans VERSION ${VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

### Dependencies ##############################################################

set(SRC_PATH "src/")
set(TEST_PATH "test/")
include_directories("inc/")

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  conan_basic_setup()
  find_package(Threads REQUIRED)
  set(DLIB dlib openblas ${CMAKE_THREAD_LIBS_INIT})
else()
  find_package(dlib)
  set(DLIB dlib::dlib)
endif()

### Main targets ##############################################################

add_library(
  ${CMAKE_PROJECT_NAME}-obj
  STATIC
  ${SRC_PATH}/clusterer.cpp
  ${SRC_PATH}/get_arg.cpp)

add_executable(
  ${CMAKE_PROJECT_NAME}
  ${SRC_PATH}/main.cpp)
target_link_libraries(
  ${CMAKE_PROJECT_NAME}
  ${CMAKE_PROJECT_NAME}-obj
  ${DLIB})

### Packing ###################################################################

install(TARGETS ${CMAKE_PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_CONTACT bergentroll@insiberia.net)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)
