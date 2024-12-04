#ifndef CONSOLERENDER_H
#define CONSOLERENDER_H
#include <string>
using namespace std;
class ConsoleRender {
public:
    ConsoleRender();
    void startMenu();
private:
    string getMenu();
};
#endif