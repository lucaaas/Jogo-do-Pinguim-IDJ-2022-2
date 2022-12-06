//
// Created by lucas on 28/11/22.
//

#include "GameObject.h"

GameObject::GameObject() : isDead(false) {}

GameObject::~GameObject() {
    for (int i = components.size() - 1; i >= 0; i--) {
        RemoveComponent(components[i]);
        delete components[i];
    }

    components.clear();
}

void GameObject::Update(float dt) {
    std::vector<Component *>::iterator it;
    for (it = components.begin(); it != components.end(); it++) {
        (*it)->Update(dt);
    }
}

void GameObject::Render() {
    std::vector<Component *>::iterator it;
    for (it = components.begin(); it != components.end(); it++) {
        (*it)->Render();
    }
}

bool GameObject::IsDead() const {
    return isDead;
}

void GameObject::RequestDelete() {
    isDead = true;
}

void GameObject::AddComponent(Component *cpt) {
    components.push_back(cpt);
}

void GameObject::RemoveComponent(Component *cpt) {
    int indexToBeRemoved = -1;

    std::vector<Component *>::iterator it;
    int i = 0;
    for (it = components.begin(); it != components.end(); it++) {
        if (*it == cpt) {
            indexToBeRemoved = i;
            break;
        }

        i++;
    }

    if (indexToBeRemoved != -1) {
        components.erase(components.begin() + indexToBeRemoved);
    }
}

Component *GameObject::GetComponent(const std::string &type) {
    std::vector<Component *>::iterator it;
    for (it = components.begin(); it != components.end(); it++) {
        if ((*it)->Is(type)) {
            return *it;
        }
    }

    return nullptr;
}


