cmake_minimum_required(VERSION 3.23)
project(game)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED SDL2)
SET(CMAKE_CXX_LINK_FLAGS "-lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm")

add_executable(game main.cpp controllers/game/Game.cpp controllers/game/Game.h controllers/state/State.cpp controllers/state/State.h base/sprite/Sprite.cpp base/sprite/Sprite.h base/music/Music.cpp base/music/Music.h helpers/asset/AssetHelper.cpp helpers/asset/AssetHelper.h types/exceptions/Exception.cpp types/exceptions/Exception.h)
target_link_libraries(game PRIVATE SDL2)