#ifndef CONSOLERENDER_H
#define CONSOLERENDER_H
#include <string>
using namespace std;

enum class playerAction {
    ENTER,
    SPACE,
    ESCAPE
};

class ConsoleRender {
public:
    ConsoleRender();
    void Menu(string);
    void update();
private:
    string getAsset(string);
};
#endif