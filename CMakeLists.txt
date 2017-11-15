cmake_minimum_required (VERSION 3.1)
project (fisica1)

if(VCPKG_CHAINLOAD_TOOLCHAIN_FILE)
    include("${VCPKG_CHAINLOAD_TOOLCHAIN_FILE}")
endif()

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(integratore ${CMAKE_SOURCE_DIR}/src/integratore.cpp)
add_executable(area_cerchio ${CMAKE_SOURCE_DIR}/src/area_cerchio.cpp)
add_executable(formula_quadratica ${CMAKE_SOURCE_DIR}/src/formula_quadratica.cpp)
add_executable(numeri_random ${CMAKE_SOURCE_DIR}/src/numeri_random.cpp)
add_executable(oscillatore ${CMAKE_SOURCE_DIR}/src/oscillatore.cpp)

