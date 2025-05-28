cmake_minimum_required(VERSION 3.28)
project(Game LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/lib/ecs/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

add_executable(Game ${SOURCES})
target_compile_features(Game PRIVATE cxx_std_20)

target_include_directories(Game PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/lib/ecs/include
)

target_link_libraries(Game PRIVATE SFML::Graphics)

# Copy assets folder for textures etc
add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/common/assets
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
)
