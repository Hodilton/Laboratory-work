#pragma once
#include "./tcp_state.hpp"

class TCPConnection {
private:
    TCPState* state;

public:
    TCPConnection() : state(nullptr) {}

public:
    void SetState(TCPState* newState) {
        state = newState;
    }

    void Open() { 
        if (state) state->Open(); 
    }
    
    void Close() {
        if (state) state->Close();
    }

    void Confirm() {
        if (state) state->Confirm();
    }
};