#pragma once
#include <string>

class Subject;

class Observer {
public:
    virtual void Update(Subject* subject) = 0;
};