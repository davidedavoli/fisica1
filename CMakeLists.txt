cmake_minimum_required (VERSION 3.1)
project (fisica1)
set(CMAKE_CXX_STANDARD 11)

macro(configure_link_flags)
  # Set compiler options.
  set(MSVC_C_CXX_FLAGS
    CMAKE_C_FLAGS_DEBUG
    CMAKE_C_FLAGS_MINSIZEREL
    CMAKE_C_FLAGS_RELEASE
    CMAKE_C_FLAGS_RELWITHDEBINFO
    CMAKE_CXX_FLAGS_DEBUG
    CMAKE_CXX_FLAGS_MINSIZEREL
    CMAKE_CXX_FLAGS_RELEASE
    CMAKE_CXX_FLAGS_RELWITHDEBINFO
  )
  if(${VCPKG_TARGET_TRIPLET} MATCHES "static")
    message(STATUS
      "VCPKG: static link"
    )
    foreach(flag ${MSVC_C_CXX_FLAGS})
      if(${flag} MATCHES "/MD")
        string(REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}")
      endif()
    endforeach()
  else()
    message(STATUS
      "VCPKG: dynamic link"
    )
    foreach(flag ${MSVC_C_CXX_FLAGS})
      if(${flag} MATCHES "/MT")
        string(REGEX REPLACE "/MT" "/MD" ${flag} "${${flag}}")
      endif()
    endforeach()
  endif()
endmacro()

macro(print_link_flags)
  set(MSVC_C_CXX_FLAGS
    CMAKE_C_FLAGS_DEBUG
    CMAKE_C_FLAGS_MINSIZEREL
    CMAKE_C_FLAGS_RELEASE
    CMAKE_C_FLAGS_RELWITHDEBINFO
    CMAKE_CXX_FLAGS_DEBUG
    CMAKE_CXX_FLAGS_MINSIZEREL
    CMAKE_CXX_FLAGS_RELEASE
    CMAKE_CXX_FLAGS_RELWITHDEBINFO
  )
  message(STATUS "Initial build flags:")
  foreach(flag ${MSVC_C_CXX_FLAGS})
    message(STATUS "  '${flag}': ${${flag}}")
  endforeach()
  message(STATUS "")
endmacro()

if(MSVC)
  add_definitions(-D_SCL_SECURE_NO_WARNINGS)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  configure_link_flags()
  #print_link_flags()
endif()

# make sure that the default is a RELEASE
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RELEASE)
endif()


### Set output directories on a per-configuration base
# Single configuration
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )
# Multi configuration
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/bin )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )


find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(integratore ${CMAKE_SOURCE_DIR}/src/integratore.cpp)
add_executable(area_cerchio ${CMAKE_SOURCE_DIR}/src/area_cerchio.cpp)
add_executable(formula_quadratica ${CMAKE_SOURCE_DIR}/src/formula_quadratica.cpp)
add_executable(numeri_random ${CMAKE_SOURCE_DIR}/src/numeri_random.cpp)
add_executable(oscillatore ${CMAKE_SOURCE_DIR}/src/oscillatore.cpp)

