#pragma once
#include "./tcp_state.hpp"
#include <iostream>

class TCPListen : public TCPState {
public:
    void Open() override {
        std::cout << "TCPListen: Transition to TCPEstablished\n";
    }
    
    void Close() override {
        std::cout << "TCPListen: Transition to TCPClosed\n";
    }
    
    void Confirm() override {
        std::cout << "TCPListen: Confirmed\n";
    }
};