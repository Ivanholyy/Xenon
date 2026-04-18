cmake_minimum_required(VERSION 3.5)

project(Xenon VERSION 0.0.0)

find_package(OpenGL REQUIRED)

set(SRC src)

set(INCLUDE include)

set(SOURCE_FILES
    ${SRC}/main.cpp
    ${INCLUDE}/glad/glad.c
    ${SRC}/log/log.cpp
    ${SRC}/shaders/shader.cpp
    ${SRC}/file.cpp
    ${SRC}/shaders/program.cpp
    ${SRC}/window/window.cpp
    ${SRC}/engine.cpp
    ${SRC}/texture/texture.cpp
    ${INCLUDE}/stb/stb_image.cpp
)

set(HEADER_FILES
    ${INCLUDE}/glad/glad.h
    ${SRC}/log/log.h
    ${SRC}/shaders/shader.h
    ${SRC}/buffer/buffer.h
    ${SRC}/file.h
    ${SRC}/shaders/program.h
    ${SRC}/window/window.h
    ${SRC}/engine.h
    ${SRC}/vao/vao.h
    ${INCLUDE}/stb/stb_image.h
    ${SRC}/texture/texture.h
)

add_executable(Xenon
    ${SOURCE_FILES}
    ${HEADER_FILES}
)

target_link_libraries(Xenon
 PUBLIC
  #opengl32
  #glew32
  glfw
  OpenGL::GL
)

target_include_directories(Xenon
 PUBLIC
 ${CMAKE_SOURCE_DIR}/external/glew/include
 ${CMAKE_SOURCE_DIR}/external/glfw/include
 ${CMAKE_SOURCE_DIR}/external/glm
 ${CMAKE_SOURCE_DIR}/external/stb
 ${CMAKE_SOURCE_DIR}/include
)
