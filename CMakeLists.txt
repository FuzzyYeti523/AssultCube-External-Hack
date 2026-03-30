cmake_minimum_required(VERSION 4.0.2)
project(AssultCube-External-Hack)

add_executable(ExternalHack)

target_compile_options(ExternalHack PRIVATE /utf-8)
target_compile_definitions(ExternalHack
    PRIVATE
    UNICODE
    _UNICODE
)

file(GLOB EXTERNAL_SRC
    ${CMAKE_SOURCE_DIR}/lib/Utility/external/src/*.cpp
)

target_include_directories(ExternalHack
    PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/Utility/external/include
     ${CMAKE_SOURCE_DIR}/lib/spdlog/include
)

target_sources(ExternalHack
    PRIVATE
    main.cpp
    ${EXTERNAL_SRC}
)