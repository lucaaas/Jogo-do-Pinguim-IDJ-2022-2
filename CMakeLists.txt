cmake_minimum_required(VERSION 3.6)
project(game)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED SDL2)
SET(CMAKE_CXX_LINK_FLAGS "-lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm -std=c++11 -Wall -Wextra -c -I include")

add_executable(game main.cpp controllers/game/Game.cpp controllers/game/Game.h controllers/state/State.cpp controllers/state/State.h base/sprite/Sprite.cpp base/sprite/Sprite.h base/music/Music.cpp base/music/Music.h helpers/asset/AssetHelper.cpp helpers/asset/AssetHelper.h types/exceptions/exception/Exception.cpp types/exceptions/exception/Exception.h base/rect/Rect.cpp base/rect/Rect.h base/vec2/Vec2.cpp base/vec2/Vec2.h base/component/Component.cpp base/component/Component.h controllers/gameObject/GameObject.cpp controllers/gameObject/GameObject.h base/sound/Sound.cpp base/sound/Sound.h mechanics/Face.cpp mechanics/Face.h types/exceptions/methodNotImplemented/MethodNotImplementedException.cpp types/exceptions/methodNotImplemented/MethodNotImplementedException.h types/consts/Consts.h)
target_link_libraries(game PRIVATE SDL2)