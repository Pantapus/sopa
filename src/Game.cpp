#include "Game.hpp"
#include "Menu.hpp"
#include <chrono>
#include <synchapi.h>
#include <iostream>

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
    constexpr int desiredFramedelay = 1000 / 30; // max 30 fps
    auto lastTime = std::chrono::high_resolution_clock::now();
    while(running) {
        draw();
        logic();
        auto currentTime = std::chrono::high_resolution_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime).count();
        if (elapsedTime < desiredFramedelay) {
            Sleep(desiredFramedelay - elapsedTime);
        }
        lastTime = std::chrono::high_resolution_clock::now();
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