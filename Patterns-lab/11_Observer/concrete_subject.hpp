#pragma once
#include "./subject.hpp"

class ConcreteSubject : public Subject {
public:
    int GetState() const {
        return subjectState;
    }

    void SetState(int state) {
        subjectState = state;
        Notify(); // сообщяем всем обсерверам обновить состояние
    }

private:
    int subjectState = 0;
};