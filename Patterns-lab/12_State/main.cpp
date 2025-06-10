#include "./tcp_connection.hpp"
#include "./tcp_established.hpp"
#include "./tcp_listen.hpp"
#include "./tcp_closed.hpp"

int main() {
    TCPConnection conn;
    TCPState* established = new TCPEstablished();
    TCPState* listen = new TCPListen();
    TCPState* closed = new TCPClosed();

    conn.SetState(established);
    conn.Open();
    conn.Close();
    conn.Confirm();

    conn.SetState(closed);
    conn.Open();
    conn.Close();
    conn.Confirm();

    conn.SetState(listen);
    conn.Open();
    conn.Close();
    conn.Confirm();

    delete established;
    delete listen;
    delete closed;

    return 0;
}