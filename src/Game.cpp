#include "Game.hpp"
#include "Menu.hpp"

bool running;
ConsoleRender render;
Input input;

Game::Game() {
    Menu menu(render, input);
    menu.startMenu();
    running = true;
    gameLoop();
}

void Game::gameLoop() {
    while(running) {
        draw();
        playerInput();
        logic();
    }
}

void Game::draw() {
    render.update();
}

void Game::playerInput() {
    Key pressedKey = input.getKey();
    if (pressedKey == ESCAPE) running = false;
}

void Game::logic() {

}