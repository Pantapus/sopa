#include "ConsoleRender.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

ConsoleRender::ConsoleRender() { 
}

void ConsoleRender::startMenu() {
    string menu = getMenu();
    cout << menu;
}

string ConsoleRender::getMenu() {
    ifstream file("../assets/startMenu.txt");
    if (!file.is_open()) {
        return "error...";
    }

    ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}