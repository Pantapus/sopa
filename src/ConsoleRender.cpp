#include "ConsoleRender.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

ConsoleRender::ConsoleRender() {
}

void ConsoleRender::Menu(string heading) {
    string menu = getAsset(heading);
    cout << menu;
}

void ConsoleRender::update() {
    system("cls");

}

string ConsoleRender::getAsset(string asset) {
    ifstream file("assets/" + asset + ".txt");
    if (!file.is_open()) {
        return "error...";
    }

    ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}