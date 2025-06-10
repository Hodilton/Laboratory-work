#pragma once
#include "./subject.hpp"

class ConcreteSubject : public Subject {
public:
    int GetState() const {
        return subjectState;
    }

    void SetState(int state) {
        subjectState = state;
        Notify(); // �������� ���� ���������� �������� ���������
    }

private:
    int subjectState = 0;
};