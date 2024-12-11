#ifndef CONSOLERENDER_H
#define CONSOLERENDER_H
#include <string>
#include "Compositor.hpp"

class ConsoleRender {
public:
    ConsoleRender(Compositor& compositor);
    void Menu(std::string);
    void update();
private:
    std::string getAsset(std::string);
    Compositor& compositor;
};
#endif