//
// Created by lucas on 30/11/22.
//

#include "MethodNotImplementedException.h"

MethodNotImplementedException::MethodNotImplementedException(const std::string &methodName)
        : Exception("Method " + methodName + " not implemented") {}
