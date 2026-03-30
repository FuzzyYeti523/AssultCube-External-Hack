cmake_minimum_required(VERSION 4.0.2)
project(AssultCube-External-Hack)

add_executable(ExternalHack)

file(GLOB EXTERNAL_SRC
    ${CMAKE_SOURCE_DIR}/lib/external/Utility/src/*.cpp
)

target_include_directories(ExternalHack
    PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/external/Utility/include
)

target_sources(ExternalHack
    PRIVATE
    main.cpp
    ${EXTERNAL_SRC}
)