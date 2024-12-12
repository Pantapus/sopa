#include "Menu.hpp"

Menu::Menu(ConsoleRender& render, Input& input) : render(render), input(input) {}

void Menu::startMenu() {
    render.Menu("startMenu");
    while (input.getKey() != ENTER) {}
}

int Menu::pauseMenu() {
    render.Menu("pauseMenu");
    while(true) {
        switch (input.getKey()) {
            case ONE:
                return 1;
            case TWO:
                return 2;
        }
    }
}