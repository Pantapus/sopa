#include "Game.hpp"
#include "ConsoleRender.hpp"
#include "Menu.hpp"

Game::Game() {
    ConsoleRender render;
    Input input;
    Menu menu(render, input);
    menu.startMenu();
}

void Game::gameLoop() {

}