//
// Created by goust on 05.11.2018.
//

#pragma once
#include "string"

using namespace std;

class Exception {
    string message;

public:
    Exception (string message);
    string getMessage ();
};
