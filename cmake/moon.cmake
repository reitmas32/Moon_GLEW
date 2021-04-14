
set(MOON_INCLUDE_DIR 
    ${CMAKE_SOURCE_DIR}/vendor 
    ${CMAKE_SOURCE_DIR}/vendor/Moon/template 
    ${CMAKE_SOURCE_DIR}/vendor/Moon/include 
    ${CMAKE_SOURCE_DIR}/vendor/Moon/vendor/spdlog/include)

#########################
#       Lib Moon        #
#########################

option(LOGS "ON")
if(${LOGS} STREQUAL "OFF")
    add_compile_definitions(RELEASE)
    set(MOON_LIBRARIES ${MOON_LIBRARIES} ${CMAKE_SOURCE_DIR}/vendor/Moon/vendor/spdlog/build/libspdlog.a)
    set(MOON_LIBRARIES ${CMAKE_SOURCE_DIR}/vendor/Moon/build/libmoon.a)
else()
    #set(MOON_LIBRARIES ${MOON_LIBRARIES} ${CMAKE_SOURCE_DIR}/vendor/Moon/build/vendor/spdlog/build/libspdlog.a)
    set(MOON_LIBRARIES ${CMAKE_SOURCE_DIR}/vendor/Moon/build/libmoon.a)
endif()
