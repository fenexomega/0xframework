project(0xframework CXX C)
cmake_minimum_required(VERSION 2.8)
include(sources.cmake)
set(SRC_LIST ${ENGINE_SOURCES} ${GAME_SHADERS} ${ENGINE_HEADERS})
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeInclude)


file(COPY ${GAME_SHADERS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR} )

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)

# the FindOpenGL.cmake file sets the value of
# OPENGL_LIBRARY to /usr/local/lib/libGL.so,
# this place uses an old version of the libGL.
if(UNIX)
    set(OPENGL_LIBRARY "/usr/lib/libGL.so")
endif()

add_executable(${CMAKE_PROJECT_NAME} ${SRC_LIST})

# If using g++, we need to set the c++11 standart and
# the -rdynamic flag for backtrace.
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message("Compiller is GNU. Using the needed flags")
    set(CMAKE_CXX_FLAGS "-std=c++11 -rdynamic")
endif()

if(NOT CMAKE_BUILD_TYPE )
	message("Building the debug version")
        set(CMAKE_BUILD_TYPE Debug CACHE STRING "Type of build: release of debug" FORCE)
else()
	add_definitions(-DRELEASE)
endif()

include_directories(src ${SDL2_INCLUDE_DIRECTORY} ${SDL2IMAGE_INCLUDE_DIR} ${GLEW_INCLUDE_DIRECTORY} ${OpenGL_INCLUDE_DIRECTORY} ${GLM_LIRBARY})
target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARY} ${GLEW_LIBRARIES} ${OPENGL_LIBRARY})


