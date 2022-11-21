cmake_minimum_required(VERSION 3.23)
project(game)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED SDL2)
SET(CMAKE_CXX_LINK_FLAGS "-lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm")

add_executable(game main.cpp controllers/Game.cpp controllers/Game.h controllers/State.cpp controllers/State.h base/Sprite.cpp base/Sprite.h base/Music.cpp base/Music.h helpers/asset/AssetHelper.cpp helpers/asset/AssetHelper.h)
target_link_libraries(game PRIVATE SDL2)