#ifndef CONSOLERENDER_H
#define CONSOLERENDER_H
#include <string>

class ConsoleRender {
public:
    void Menu(std::string);
    void update();
private:
    std::string getAsset(std::string);
};
#endif