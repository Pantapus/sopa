#include "Menu.hpp"
#include <synchapi.h>

Menu::Menu(ConsoleRender& render, Input& input) : render(render), input(input) {}

void Menu::startMenu() {
    render.Menu("startMenu");
    Sleep(500);
    while (input.getKey() != ENTER) {}
}

int Menu::pauseMenu() {
    render.Menu("pauseMenu");
    Sleep(500);
    while(true) {
        switch (input.getKey()) {
            case ONE:
                return 1;
            case TWO:
                return 2;
        }
    }
}