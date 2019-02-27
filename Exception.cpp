//
// Created by goust on 05.11.2018.
//

#include "Exception.h"

Exception::Exception(string message) {
    this -> message = message;
}

string Exception::getMessage() {
    return message;
}
