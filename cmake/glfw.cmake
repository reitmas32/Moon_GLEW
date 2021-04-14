option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_INSTALL OFF)
add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/glfw)

set_target_properties(glfw PROPERTIES FOLDER vendor) # Override standard 'GLFW3' subfolder

set(GLFW_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/vendor/glfw/include ${CMAKE_SOURCE_DIR}/vendor/glfw/deps)
set(GLFW_DEFINITIONS -DGLFW_INCLUDE_NONE)
set(GLFW_LIBRARIES ${GLFW_LIBRARIES} glfw)

if (${WIN32})
  set(GLFW_LIBRARIES ${GLFW_LIBRARIES} gdi32)
endif ()