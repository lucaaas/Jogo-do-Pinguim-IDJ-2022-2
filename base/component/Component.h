//
// Created by lucas on 27/11/22.
//

#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H


#include <string>
#include "../../controllers/gameObject/GameObject.h"

class GameObject;

/**
 * Abstract class that represents a game's component.
 */
class Component {
protected:
    GameObject &associated;

public:
    /**
     * Creates a component with a GameObject associated
     * @param associated
     */
    explicit Component(GameObject &associated);

    virtual ~Component();

    /**
     * Updates this state
     * @param dt
     */
    virtual void Update(float dt) = 0;

    /**
     * Renders this in the window
     */
    virtual void Render() = 0;

    /**
     * Determines this type
     * @param type
     * @return true if this is of the `type`
     */
    virtual bool Is(std::string type) = 0;
};


#endif //GAME_COMPONENT_H
