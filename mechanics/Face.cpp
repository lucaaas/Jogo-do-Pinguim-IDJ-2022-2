//
// Created by lucas on 29/11/22.
//

#include "Face.h"
#include "../base/sound/Sound.h"
#include "../types/exceptions/exception/Exception.h"
#include "../controllers/inputManager/InputManager.h"

Face::Face(GameObject &associated) : Component(associated) {
    hitpoints = 30;
}

void Face::Damage(int damage) {
    hitpoints -= damage;

    if (hitpoints <= 0) {
        Sound *sound = (Sound *) associated.GetComponent("Sound");
        sound->Play();

        associated.RequestDelete();
    }
}

bool Face::Is(std::string type) {
    return type == "Face";
}

void Face::Update(float dt) {
    InputManager &inputManager = InputManager::GetInstance();

    if (inputManager.MousePress(LEFT_MOUSE_BUTTON)) {
        if (associated.box.Contains(inputManager.GetMouseX(), inputManager.GetMouseY())) {
            Damage(std::rand() % 10 + 10);
        }
    }
}

void Face::Render() {
    // do nothing
}
