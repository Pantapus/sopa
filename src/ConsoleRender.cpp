#include "ConsoleRender.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
using std::cout, std::string;

ConsoleRender::ConsoleRender(Compositor& compositor) : compositor(compositor) {}

void ConsoleRender::Menu(string heading) {
    string menu = getAsset(heading);
    system("cls");
    cout << menu;
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

string ConsoleRender::getAsset(string asset) {
    std::ifstream file("assets/" + asset + ".txt");
    if (!file.is_open()) {
        return "error...";
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}