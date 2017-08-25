cmake_minimum_required (VERSION 3.1)
project (fisica1)
set (CMAKE_CXX_STANDARD 11)

if (MSVC)
  add_definitions(-D_SCL_SECURE_NO_WARNINGS)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

find_package(Boost REQUIRED)

include_directories("${Boost_INCLUDE_DIRS}") 
include_directories("${PROJECT_BINARY_DIR}") 

add_executable(integratore ${CMAKE_SOURCE_DIR}/src/integratore.cpp)
add_executable(area_cerchio ${CMAKE_SOURCE_DIR}/src/area_cerchio.cpp)
add_executable(formula_quadratica ${CMAKE_SOURCE_DIR}/src/formula_quadratica.cpp)
add_executable(numeri_random ${CMAKE_SOURCE_DIR}/src/numeri_random.cpp)
add_executable(oscillatore ${CMAKE_SOURCE_DIR}/src/oscillatore.cpp)

install (TARGETS integratore area_cerchio formula_quadratica numeri_random oscillatore 
  DESTINATION ${CMAKE_SOURCE_DIR}/bin/)
