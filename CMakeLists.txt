cmake_minimum_required(VERSION 3.1)

project(space_invaders)

set(CMAKE_CXX_STANDARD 14)

set(srcdir "src")
set(EXECUTABLE_NAME space_invaders)

set(CMAKE_MODULE_PATH  "/usr/share/SFML/cmake/Modules")
set(CMAKE_PREFIX_PATH  "/usr/share/SFML")

message("${CMAKE_BUILD_RPATH}")

add_executable(
    ${EXECUTABLE_NAME}
    ${srcdir}/main.cpp
    ${srcdir}/Character.cpp
    ${srcdir}/Character.h
    ${srcdir}/Enemi.cpp
    ${srcdir}/Enemi.h
    ${srcdir}/Entity.cpp
    ${srcdir}/Entity.h
    ${srcdir}/Game.cpp
    ${srcdir}/Game.h
    ${srcdir}/GameWindow.cpp
    ${srcdir}/GameWindow.h
    ${srcdir}/Hitbox.cpp
    ${srcdir}/Hitbox.h
    ${srcdir}/HitboxManager.cpp
    ${srcdir}/HitboxManager.h
    ${srcdir}/Layer.cpp
    ${srcdir}/Layer.h
    ${srcdir}/Missile.cpp
    ${srcdir}/Missile.h
    ${srcdir}/Ship.cpp
    ${srcdir}/Ship.h
    ${srcdir}/SpriteManager.cpp
    ${srcdir}/SpriteManager.h
    ${srcdir}/Ressources.cpp
    ${srcdir}/Ressources.h
    ${srcdir}/TextManager.cpp
    ${srcdir}/TextManager.h
)

find_package(SFML 2 REQUIRED audio graphics window system)

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

set(CMAKE_MODULE_PATH "/usr/share/SFML/Modules" ${CMAKE_MODULE_PATH})

# Resources
file(COPY "${CMAKE_SOURCE_DIR}/data" DESTINATION .)