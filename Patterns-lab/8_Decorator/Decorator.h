#pragma once

#include <iostream>

class VisualComponent {
public:
    virtual void Draw() = 0;
};


class TextView : public VisualComponent {
public:
    void Draw() override {
        std::cout << "Draw TextView" << std::endl;
    }
};


class Decorator : public VisualComponent {
protected:
    VisualComponent* component;

public:
    Decorator(VisualComponent* comp)
        : component(comp) {
    }

    virtual ~Decorator() = 0 {
        delete component;
    }

public:
    virtual void Draw() = 0 {
        if (component) {
            component->Draw();
        }
    }
};


class ScrollDecorator : public Decorator {
private:
    int scrollPosition;

public:
    ScrollDecorator(VisualComponent* comp, int position = 0)
        : Decorator(comp), scrollPosition(position) {
    }

    void Draw() override {
        Decorator::Draw();
        ScrollTo();
    }

    void ScrollTo() {
        std::cout << "Scroll to position: " << scrollPosition << std::endl;
    }
};

class BorderDecorator : public Decorator {
private:
    int borderWidth;

public:
    BorderDecorator(VisualComponent* comp, int width = 1)
        : Decorator(comp), borderWidth(width) {
    }

public:
    void Draw() override {
        Decorator::Draw();
        DrawBorder();
    }

    void DrawBorder() {
        std::cout << "Draw border of width: " << borderWidth << std::endl;
    }
};