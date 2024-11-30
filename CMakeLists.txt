# CMakeList.txt : CMake project for RaylibGameTemplate, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("RaylibGameTemplate")

include(FetchContent)

# Dependencies
set(RAYLIB_VERSION 5.0)

FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS
)

FetchContent_MakeAvailable(raylib)

# Add source to this project's executable.
add_executable (RaylibGameTemplate "src/main.cpp" "src/constants.h" "src/util/TexturePool.h" "src/util/TexturePool.cpp" "src/util/hash.h" "src/util/hash.cpp" "src/scene/SceneID.h" "src/scene/Scene.h" "src/scene/Scene.cpp" "src/scene/TitleScreen.cpp" "src/ecs/ComponentManager.h" "src/util/types.h" "src/ecs/ComponentArray.h" "src/ecs/ComponentArray.cpp" "src/ecs/components.h" "src/ecs/ComponentManager.cpp" "src/ecs/EntityManager.h" "src/ecs/EntityManager.cpp" "src/ecs/SystemManager.h" "src/ecs/TransformSystem.cpp" "src/ecs/SpriteSystem.cpp" "src/ecs/SpriteAnimationSystem.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RaylibGameTemplate PROPERTY CXX_STANDARD 20)
endif()

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/src/resources $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)

#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)
