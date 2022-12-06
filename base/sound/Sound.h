//
// Created by lucas on 29/11/22.
//

#ifndef GAME_SOUND_H
#define GAME_SOUND_H


#include <SDL2/SDL_mixer.h>
#include "../component/Component.h"
#include "../../controllers/gameObject/GameObject.h"

/**
 * Class to play and control sounds
 */
class Sound : public Component {
private:
    Mix_Chunk* chunk;
    int channel;

public:
    explicit Sound(GameObject& associated);

    Sound(GameObject& associated, const std::string& file);

    ~Sound() override;

    /**
     * Plays the sound and repeats for `times` times. For a infinity looping pass -1
     * @param times number of times to repeat the sound. Defaults to 1
     */
    void Play(int times = 1);

    /**
     * Stops the current channel
     */
    void Stop();

    /**
     * Opens a music `file`
     * @param file file to be open
     * @throws Exception if the file does not exists
     */
    void Open(const std::string& file);

    /**
     * Checks if the file is open
     * @return true if it is open
     */
    bool IsOpen();

    void Update(float dt) override;

    void Render() override;

    bool Is(std::string type) override;
};


#endif //GAME_SOUND_H
