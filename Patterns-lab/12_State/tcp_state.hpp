#pragma once

class TCPState {
public:
    virtual void Open() = 0;
    virtual void Close() = 0;
    virtual void Confirm() = 0;
};