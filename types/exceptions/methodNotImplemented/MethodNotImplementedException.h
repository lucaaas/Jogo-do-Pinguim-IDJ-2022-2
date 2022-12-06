//
// Created by lucas on 30/11/22.
//

#ifndef GAME_METHODNOTIMPLEMENTEDEXCEPTION_H
#define GAME_METHODNOTIMPLEMENTEDEXCEPTION_H


#include "../exception/Exception.h"

class MethodNotImplementedException : public Exception {
public:
    /**
     * Creates an Exception to when a method is not implemented
     * @param methodName name of the not implemented method
     */
    explicit MethodNotImplementedException(const std::string &methodName);
};


#endif //GAME_METHODNOTIMPLEMENTEDEXCEPTION_H
