#pragma once

class Singleton {
private:
    static Singleton* _instance;

protected:
    Singleton() {}

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton* getInstance() {
        if (!_instance) {
            _instance = new Singleton;
        }

        return _instance;
    }

    static void CleanApp() {
        if (_instance) {
            delete _instance;
        }
        
        _instance = nullptr;
    }
};

Singleton* Singleton::_instance = nullptr;