#include "./Bridge.cpp"
using namespace bridge;

#include <Windows.h>

int main() {
    SetConsoleOutputCP(1251);

    XWindowImp xImp;
    PMWindowImp pmImp;

    IconWindow iconWin(&xImp);
    TransientWindow transWin(&pmImp);

    std::cout << "IconWindow\n";
    iconWin.Draw_Text();
    iconWin.Draw_Rect();
    iconWin.DrawBorder();

    std::cout << "\nTransientWindow\n";
    transWin.Draw_Text();
    transWin.Draw_Rect();
    transWin.DrawCloseBox();

	return 0;
}