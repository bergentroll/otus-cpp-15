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

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.65 COMPONENTS program_options)
find_package(dlib)

find_package(Threads REQUIRED)

### Main targets ##############################################################

# add_library(
#   ${CMAKE_PROJECT_NAME}-obj
#   STATIC
#   ${SRC_PATH} ... )

add_executable(
  ${CMAKE_PROJECT_NAME}
  ${SRC_PATH}/main.cpp)
target_link_libraries(
  ${CMAKE_PROJECT_NAME}
  #${CMAKE_PROJECT_NAME}-obj
  ${Boost_PROGRAM_OPTIONS_LIBRARY}
  dlib::dlib)

### Packing ###################################################################

install(TARGETS ${CMAKE_PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_CONTACT bergentroll@insiberia.net)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)
