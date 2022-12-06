//
// Created by lucas on 29/11/22.
//

#ifndef GAME_FACE_H
#define GAME_FACE_H


#include "../base/component/Component.h"

/**
 * Represents an enemy
 */
class Face : public Component {
private:
    int hitpoints;

public:
    explicit Face(GameObject &associated);

    /**
     * Causes damage to this reducing its hit points. If hit points <= 0, then this is destroyed.
     * @param damage number of hit points to reduce
     */
    void Damage(int damage);

    bool Is(std::string type) override;

    void Update(float dt) override;

    void Render() override;

};


#endif //GAME_FACE_H
