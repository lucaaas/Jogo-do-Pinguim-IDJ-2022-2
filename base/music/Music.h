//
// Created by lucas on 13/11/22.
//

#ifndef GAME_MUSIC_H
#define GAME_MUSIC_H

#include <string>
#include "SDL2/SDL_mixer.h"

/***
 * @class Music
 * @def Class used to play audio files
 */
class Music {
private:
    Mix_Music *music;

public:
    /***
     * Simple constructor that initializes all members as nullptr
     */
    Music();

    /***
     * Opens an audio file
     *
     * @param file: char*: audio to be opened
     */
    explicit Music(std::string file);

    /**
     * Calls `Stop()`
     */
    ~Music();

    /**
     * Plays the music and repeats for `times` times. For a infinity looping pass -1
     * @param times number of times to repeat the music. Defaults to -1
     */
    void Play(int times = -1);

    /**
     * Stops the current playing music
     * @param msToStop milliseconds to stop completely, making a fade effect. To stop immediately pass 0.  Defaults to 1500 ms
     */
    void Stop(int msToStop = 1500);

    /**
     * Opens a music `file`
     * @param file file to be open
     * @throws Exception if the file does not exists
     */
    void Open(std::string file);

    /**
     * Checks if the file is open
     * @return true if it is open
     */
    bool IsOpen();
};


#endif //GAME_MUSIC_H
