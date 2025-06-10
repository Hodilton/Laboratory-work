#pragma once
#include "./tcp_state.hpp"
#include <iostream>

class TCPEstablished : public TCPState {
public:
    void Open() override {
        std::cout << "TCPEstablished: Already open" << std::endl;
    }
    
    void Close() override {
        std::cout << "TCPEstablished: Transition to TCPClosed" << std::endl;
    }
    
    void Confirm() override {
        std::cout << "TCPEstablished: Confirmed" << std::endl;
    }
};