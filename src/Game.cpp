#include "Game.hpp"
#include "Menu.hpp"

bool running;
ConsoleRender render;
Input input;
Menu menu(render, input);

Game::Game() {
    menu.startMenu();
    running = true;
    gameLoop();
}

void Game::gameLoop() {
    while(running) {
        draw();
        logic();
    }
}

void Game::draw() {
    render.update();
}

void Game::logic() {
    Key playerAction = input.getKey();
    switch (playerAction) {
        case ESCAPE:
            pause();
            break;
    }
}

void Game::pause() {
    int choice = menu.pauseMenu();
    if (choice == 2) running = false;
}