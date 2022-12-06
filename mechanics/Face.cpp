//
// Created by lucas on 29/11/22.
//

#include "Face.h"
#include "../base/sound/Sound.h"
#include "../types/exceptions/exception/Exception.h"
#include "../types/exceptions/methodNotImplemented/MethodNotImplementedException.h"

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
    // do nothing
}

void Face::Render() {
    // do nothing
}
