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
    static const char* symbols[] = {" ", "#", "@", "8", "$"};
    system("cls");
    for (int i = 0; i < compositor.ROWS; i++) {
        for (int j = 0; j < compositor.COLS; j++) {
            cout << symbols[compositor.gameWorld[i][j]];
        }
        cout << "\n";
    }
}

void ConsoleRender::setCursorPosition(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(consoleHandle, position);
}