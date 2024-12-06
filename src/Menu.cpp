#include "Menu.hpp"
#include <synchapi.h>

Menu::Menu(ConsoleRender& render, Input& input) : render(render), input(input) {}

void Menu::startMenu() {
    render.Menu("startMenu");
    Sleep(1000);
    while (input.getKey() != ENTER) {}
}

int Menu::pauseMenu() {
    return 1;
}