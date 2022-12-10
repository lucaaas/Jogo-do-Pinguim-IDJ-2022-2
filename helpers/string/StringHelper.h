//
// Created by lucas on 09/12/22.
//

#ifndef GAME_STRINGHELPER_H
#define GAME_STRINGHELPER_H


#include <string>
#include <vector>

class StringHelper {
public:
    static std::vector<std::string> Split(std::string string, std::string delimiter);

    static std::string LTrim(std::string text);

    static std::string RTrim(std::string text);

    static std::string Trim(std::string text);
};


#endif //GAME_STRINGHELPER_H
