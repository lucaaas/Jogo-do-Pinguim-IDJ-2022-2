//
// Created by lucas on 13/11/22.
//

#include "State.h"
#include "../../helpers/asset/AssetHelper.h"
#include "../../mechanics/Face.h"
#include "../../base/sound/Sound.h"
#include "../../types/consts/Consts.h"
#include "../../types/exceptions/exception/Exception.h"
#include "../game/Game.h"
#include "../../base/TileMap.h"

GameObject backgroundGO = GameObject();

State::State() : music(AssetHelper::GetAssetPath("audio", "stageState.ogg")),
                 bg(Sprite(backgroundGO, AssetHelper::GetAssetPath("img", "ocean.jpg"))) {
    quitRequested = false;

    bg.Render();
    music.Play();

    AddMap();

    AddObject(0, 0);
}

State::~State() {
    objectArray.clear();
}

void State::AddObject(int mouseX, int mouseY) {
    GameObject *enemie = new GameObject();
    Sprite *sprite = new Sprite(*enemie, AssetHelper::GetAssetPath("img", "penguinface.png"));

    enemie->box = Rect(mouseX, mouseY, sprite->GetWidth(), sprite->GetHeight());

    enemie->AddComponent(sprite);
    enemie->AddComponent(new Face(*enemie));
    enemie->AddComponent(new Sound(*enemie, AssetHelper::GetAssetPath("audio", "boom.wav")));

    objectArray.emplace_back(enemie);
}

void State::LoadAssets() {
    music = Music(AssetHelper::GetAssetPath("audio", "stageState.ogg"));
    music.Play();
}

bool State::QuitRequested() const {
    return quitRequested;
}

void State::Render() {
    try {
        bg.Render();
        std::vector<std::unique_ptr<GameObject>>::iterator it;
        for (it = objectArray.begin(); it != objectArray.end(); it++) {
            (*it)->Render();
        }
    } catch (Exception err) {
//        printf("%s \n", err.what());
    }
}

void State::Update(float dt) {
    try {
        Input();

        std::vector<std::unique_ptr<GameObject>>::iterator it;
        for (it = objectArray.begin(); it != objectArray.end(); it++) {
            (*it)->Update(dt);
        }

        for (int i = 0; i < objectArray.size(); i++) {
            if (objectArray[i]->IsDead()) {
                objectArray.erase(objectArray.begin() + i);
            }
        }
    } catch (std::exception &err) {
        printf("%s \n", err.what());
    }
}

void State::AddMap() {
    GameObject *mapObject = new GameObject();
    mapObject->box = Rect(0, 0, 64, 64);

    TileSet tiles = TileSet(64, 64, AssetHelper::GetAssetPath("img", "tileset.png"));
    TileMap *map = new TileMap(*mapObject, "tileMap.txt", &tiles);

    mapObject->AddComponent(map);
    objectArray.emplace_back(mapObject);
}

void State::Input() {
    SDL_Event event;
    int mouseX, mouseY;

    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (SDL_PollEvent(&event)) {

        // Se o evento for quit, setar a flag para terminação
        if (event.type == SDL_QUIT) {
            quitRequested = true;
        }

        // Se o evento for clique...
        if (event.type == SDL_MOUSEBUTTONDOWN) {

            // Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
            for (int i = objectArray.size() - 1; i >= 0; --i) {
                // Obtem o ponteiro e casta pra Face.
                GameObject *go = (GameObject *) objectArray[i].get();
                // Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
                // O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
                // ao usar get(), violamos esse princípio e estamos menos seguros.
                // Esse código, assim como a classe Face, é provisório. Futuramente, para
                // chamar funções de GameObjects, use objectArray[i]->função() direto.

                if (go->box.Contains((float) mouseX, (float) mouseY)) {
                    Face *face = (Face *) go->GetComponent("Face");
                    if (nullptr != face) {
                        // Aplica dano
                        face->Damage(std::rand() % 10 + 10);
                        // Sai do loop (só queremos acertar um)
                        break;
                    }
                }
            }
        }
        if (event.type == SDL_KEYDOWN) {
            // Se a tecla for ESC, setar a flag de quit
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                quitRequested = true;
            }
                // Se não, crie um objeto
            else {
                Vec2 objPos = Vec2(200, 0);
                objPos.Rotate(-Consts::PI + Consts::PI * (rand() % 1001) / 500.0);
                objPos = objPos + Vec2(mouseX, mouseY);

                AddObject((int) objPos.getX(), (int) objPos.getY());
            }
        }
    }
}
