#ifndef CONSOLERENDER_H
#define CONSOLERENDER_H
#include <string>
#include <windows.h>
#include "Compositor.hpp"

class ConsoleRender {
public:
    ConsoleRender(Compositor& compositor);
    void Menu(std::string);
    void update();
private:
    std::string getAsset(std::string);
    Compositor& compositor;
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    void setCursorPosition(int x, int y);
    char getCharAtPosition(int x, int y);
};
#endif