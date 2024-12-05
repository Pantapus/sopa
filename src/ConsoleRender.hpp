#ifndef CONSOLERENDER_H
#define CONSOLERENDER_H
#include <string>
using namespace std;

class ConsoleRender {
public:
    void Menu(string);
    void update();
private:
    string getAsset(string);
};
#endif