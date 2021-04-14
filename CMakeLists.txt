########################
#     Config  of       #
#       Project        #
########################
cmake_minimum_required (VERSION 3.0.0)

set(NAME_PROJECT Moon_GLFW)

#TODO: 
set(APP moon-glfw)

if(${WIN32})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/windows.cmake)
        include(${CMAKE_CURRENT_SOURCE_DIR}/windows.cmake)
    endif()
elseif(${UNIX})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/linux.cmake)
        include(${CMAKE_CURRENT_SOURCE_DIR}/linux.cmake)
    endif()
endif()