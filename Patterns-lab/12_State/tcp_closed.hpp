#pragma once
#include "./tcp_state.hpp"
#include <iostream>

class TCPClosed : public TCPState {
public:
    void Open() override {
        std::cout << "TCPClosed: Transition to TCPListen\n";
    }
    
    void Close() override {
        std::cout << "TCPClosed: Already closed\n";
    }
    
    void Confirm() override {
        std::cout << "TCPClosed: Cannot confirmed\n";
    }
};