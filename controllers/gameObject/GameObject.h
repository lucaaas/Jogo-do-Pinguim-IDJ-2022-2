//
// Created by lucas on 28/11/22.
//

#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H


#include <vector>
#include "../../base/component/Component.h"
#include "../../base/rect/Rect.h"

class Component;

/**
 * Class to group component's logic
 */
class GameObject {
private:
    std::vector<Component *> components;
    bool isDead;

public:
    Rect box;

    explicit GameObject();

    ~GameObject();

    /**
     * Calls all Components's Update method
     * @param dt
     */
    void Update(float dt);

    /**
     * Calls all Components's Render method
     */
    void Render();

    /**
     * @return true if this is dead
     */
    bool IsDead() const;

    /**
     * Requests to delete this
     */
    void RequestDelete();

    /**
     * Adds a new Component to this
     * @param cpt Component to be added
     */
    void AddComponent(Component *cpt);

    /**
     * Removes a component, if it exists
     * @param cpt component to be removed
     */
    void RemoveComponent(Component *cpt);

    /**
     * Gets the Component of the type
     * @param type
     * @return a pointer to the requested component or nullptr if not found
     */
    Component *GetComponent(const std::string &type);
};


#endif //GAME_GAMEOBJECT_H
