#include "Menu.hpp"

Menu::Menu(ConsoleRender& render, Input& input) : render(render), input(input) {}

void Menu::startMenu() {
    render.Menu("startMenu");
    while (input.getKey() != ENTER) {}
}

int Menu::choiceMenu(std::string menu) {
    render.Menu(menu);
    while(true) {
        switch (input.getKey()) {
            case ONE:
                return 1;
            case TWO:
                return 2;
            default:
                break;
        }
    }
}

void Menu::error(const char* error) {
    std::string message(error);
    message = message + "\n" + "press ENTER to close...";
    render.printMessageAt(message, 0, 0);
    while (input.getKey() != ENTER) {}
}