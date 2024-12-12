#include "ConsoleRender.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <windows.h>
using std::cout, std::string;

ConsoleRender::ConsoleRender(Compositor& compositor) : compositor(compositor) {
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
    for (int i = 0; i < compositor.ROWS; i++) {
        for (int j = 0; j < compositor.COLS; j++) {
            if (getCharAtPosition(j, i) != compositor.gameWorld[i][j]) {
                setCursorPosition(j, i);
                cout << symbols[compositor.gameWorld[i][j]];
            }
        }
    }
}

void ConsoleRender::setCursorPosition(int x, int y) {
    COORD position = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(consoleHandle, position);
}

char ConsoleRender::getCharAtPosition(int x, int y) {
    char character;
    COORD position = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    DWORD charsRead;
    ReadConsoleOutputCharacter(consoleHandle, &character, 1, position, &charsRead);
    return character;
}