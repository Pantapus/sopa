#include "Menu.hpp"
#include <iostream>

Menu::Menu(ConsoleRender& render, Input& input) : render(render), input(input) {}

void Menu::startMenu() {
    render.Menu("startMenu");
    while (true) {
        if (input.getKey() == ENTER) {
            break;
        }
    }
}

int Menu::pauseMenu() {
    return 1;
}