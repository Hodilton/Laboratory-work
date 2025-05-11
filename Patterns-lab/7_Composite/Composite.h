#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Graphic {
public:
    virtual void Draw() const = 0;
    virtual void Add(Graphic* g) {}
    virtual void Remove(Graphic* g) {}
    virtual Graphic* GetChild(int index) const {
        return nullptr;
    }
};

class Line : public Graphic {
public:
    void Draw() const override {
        std::cout << "Draw a line" << std::endl;
    }
};

class Rectangle : public Graphic {
public:
    void Draw() const override {
        std::cout << "Drawing a rectangle" << std::endl;
    }
};

class Text : public Graphic {
public:
    void Draw() const override {
        std::cout << "Drawing text" << std::endl;
    }
};

class Picture : public Graphic {
private:
    std::vector<Graphic*> graphics;

public:
    ~Picture() {
        for (Graphic* g : graphics) {
            delete g;
        }
        graphics.clear();
    }

public:
    void Draw() const override {
        for (Graphic* g : graphics) {
            g->Draw();
        }
    }

    void Add(Graphic* g) override {
        graphics.push_back(g);
    }

    void Remove(Graphic* g) override {
        auto it = std::find(graphics.begin(), graphics.end(), g);
        if (it != graphics.end()) {
            delete* it;
            graphics.erase(it);
        }
    }

    Graphic* GetChild(int index) const override {
        if (index >= 0 && index < static_cast<int>(graphics.size())) {
            return graphics[index];
        }
    }
};