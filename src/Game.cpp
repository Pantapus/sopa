#include <iostream>
#include <windows.h>
#include <winuser.h>
#include "ConsoleRender.h"
using namespace std;

int main() {
    ConsoleRender render;
    render.startMenu();

    bool running = true;
    while (running) {
        if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
            cout << "ENTER PRESSED\n";
        }
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            cout << "SPACE PRESSED\n";
        }
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            running = false;
        }
        system("cls");
    }
    return 0;
}