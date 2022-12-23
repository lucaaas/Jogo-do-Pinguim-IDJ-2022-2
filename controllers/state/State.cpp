//
// Created by lucas on 13/11/22.
//

#include "State.h"

GameObject backgroundGO = GameObject();
InputManager &inputManager = InputManager::GetInstance();

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
        if (inputManager.IsKeyDown(ESCAPE_KEY) || inputManager.QuitRequested()) {
            quitRequested = true;
        } else if (inputManager.KeyPress(SPACE_KEY)) {
            AddFace();
        }

        UpdateObjects(dt);
        RemoveDeadObjects();
    } catch (std::exception &err) {
        printf("%s \n", err.what());
    }
}

void State::AddFace() {
    Vec2 objPos = Vec2(200, 0);
    objPos.Rotate(-Consts::PI + Consts::PI * (rand() % 1001) / 500.0);
    objPos = objPos + Vec2(inputManager.GetMouseX(), inputManager.GetMouseY());

    AddObject((int) objPos.getX(), (int) objPos.getY());
}

void State::AddMap() {
    GameObject *mapObject = new GameObject();
    mapObject->box = Rect(0, 0, 64, 64);

    TileSet tiles = TileSet(64, 64, AssetHelper::GetAssetPath("img", "tileset.png"));
    TileMap *map = new TileMap(*mapObject, "tileMap.txt", &tiles);

    mapObject->AddComponent(map);
    objectArray.emplace_back(mapObject);
}

void State::UpdateObjects(float dt) {
    vector<unique_ptr<GameObject>>::iterator it;
    for (it = objectArray.begin(); it != objectArray.end(); it++) {
        (*it)->Update(dt);
    }
}

void State::RemoveDeadObjects() {
    for (int i = 0; i < objectArray.size(); i++) {
        if (objectArray[i]->IsDead()) {
            objectArray.erase(objectArray.begin() + i);
        }
    }
}

