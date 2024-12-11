#include "ConsoleRender.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <windows.h>

using std::cout, std::string;

ConsoleRender::ConsoleRender(Compositor& compositor) : compositor(compositor) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void ConsoleRender::Menu(string heading) {
    string menu = getAsset(heading);
    system("cls");
    cout << menu;
}

string ConsoleRender::getAsset(string asset) {
    std::ifstream file("assets/" + asset + ".txt");
    if (!file.is_open()) {
        return "error...";
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void ConsoleRender::update() {
    system("cls");
    for (int i = 0; i < compositor.ROWS; i++) {
        for (int j = 0; j < compositor.COLS; j++) {
            switch (compositor.gameWorld[i][j]) {
            case WALL:
                cout << "###";
                break;
            case EMPTY:
                cout << "   ";
                break;
            }
        }
        cout << "\n";
    }
}

void ConsoleRender::setCursorPosition(int x, int y) {

}