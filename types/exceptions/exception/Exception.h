//
// Created by lucas on 22/11/22.
//

#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H


#include <string>

class Exception : public std::exception {
private:
    std::string message;

public:
    explicit Exception(std::string message);

    void Show() const;

    const char *what() const noexcept override;
};


#endif //GAME_EXCEPTION_H
