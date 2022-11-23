//
// Created by lucas on 22/11/22.
//

#include "Exception.h"

#include <utility>

Exception::Exception(std::string message) : message(std::move(message)) {}

const char *Exception::what() const noexcept {
    return message.c_str();
}