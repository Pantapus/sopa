#include "Game.hpp"
#include "Menu.hpp"
#include <chrono>
#include <exception>
#include <synchapi.h>
#include <iostream>

bool running;
Compositor compositor;
ConsoleRender render(compositor);
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

    try { compositor.setMap("map1"); } catch (const std::exception& e) {
        Sleep(1000);
        menu.error(e.what());
        running = false;
    }
    
    while(running) {
        draw();
        logic();
        auto currentTime = std::chrono::high_resolution_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime).count();
        if (elapsedTime < desiredFramedelay) {
            Sleep(desiredFramedelay - elapsedTime);
        }
        lastTime = std::chrono::high_resolution_clock::now();
        auto totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(lastTime - currentTime).count() + elapsedTime;
        std::cout << (1000 / totalTime);
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