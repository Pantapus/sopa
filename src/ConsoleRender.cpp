#include "ConsoleRender.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

ConsoleRender::ConsoleRender() { 
}

void ConsoleRender::startMenu() {
    string menu = getAsset("startMenu");
    cout << menu;
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