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
    string map = getAsset("map");
    system("cls");
    cout << map;
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