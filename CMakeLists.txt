cmake_minimum_required (VERSION 3.1)
project (fisica1)

if (EXISTS "$ENV{WORKSPACE}/sysconfig/cmake/physycom_config.cmake")
   message(STATUS "Enabling physycom settings")
   include("$ENV{WORKSPACE}/sysconfig/cmake/physycom_config.cmake")
else()
   message(STATUS "Unable to find physycom settings file")
endif()


find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(integratore ${CMAKE_SOURCE_DIR}/src/integratore.cpp)
add_executable(area_cerchio ${CMAKE_SOURCE_DIR}/src/area_cerchio.cpp)
add_executable(formula_quadratica ${CMAKE_SOURCE_DIR}/src/formula_quadratica.cpp)
add_executable(numeri_random ${CMAKE_SOURCE_DIR}/src/numeri_random.cpp)
add_executable(oscillatore ${CMAKE_SOURCE_DIR}/src/oscillatore.cpp)

install (TARGETS
    integratore
    area_cerchio
    formula_quadratica
    numeri_random
    oscillatore
    DESTINATION
    ${CMAKE_SOURCE_DIR}/bin/
)
