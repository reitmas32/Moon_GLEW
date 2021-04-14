########################
#     Main Dirs of     #
#       Project        #
########################
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

########################
#    Include Dirs of   #
#       Project        #
########################
include_directories(
    .
    ${INCLUDE_DIR}
)

########################
#    Find Source of    #
#       Project        #
########################
file( GLOB_RECURSE LIB_SOURCES ${SOURCE_DIR}/*.cpp )
file( GLOB_RECURSE LIB_HEADERS ${INCLUDE_DIR}/*.hpp )

########################
#     Add Source of    #
#       Project        #
########################
add_executable(
    ${APP} 
    ${LIB_SOURCES} 
    ${LIB_HEADERS}
)

########################
#     Config from      #
#     Build System     #
########################
if(${CMAKE_GENERATOR} STREQUAL "Ninja")
    #Todo:Ninja
endif()

if(${CMAKE_GENERATOR} STREQUAL "Visual Studio 16 2019")
    #Todo: Visual Studio
endif()

if(${CMAKE_GENERATOR} STREQUAL "NMake Makefiles")
  #Todo:NMaka
endif()

if(${CMAKE_GENERATOR} STREQUAL "MinGW Makefiles")
    #Todo:MinGW Makefile
endif()