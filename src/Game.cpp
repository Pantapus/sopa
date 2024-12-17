#include "Game.hpp"
#include "Menu.hpp"
#include <chrono>
#include <exception>
#include <synchapi.h>

Compositor* compositor;
ConsoleRender* render;
Input* input;
Menu* menu;
bool running;
int iterationNumber = 0;

Game::Game() {
    running = true;
    gameLoop();
}

void Game::gameLoop() {
    compositor = new Compositor();
    render = new ConsoleRender(*compositor);
    input = new Input();
    menu = new Menu(*render, *input);
    menu->startMenu();

    try { compositor->setMap("map1"); } catch (const std::exception& e) {
        Sleep(1000);
        menu->error(e.what());
        running = false;
    }
    auto gameStart = std::chrono::high_resolution_clock::now();
    while(running) {
        iterationNumber += 1;
        render->update();
        logic();
        auto currentTime = std::chrono::high_resolution_clock::now();
        auto totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - gameStart).count();
        while ((float)iterationNumber/totalTime > 0.015) {
            currentTime = std::chrono::high_resolution_clock::now();
            totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - gameStart).count();
        }
        render->printMessageAt(std::to_string(((float)iterationNumber/totalTime)*1000), 0, 25);
    }
    gameOver();
}

void Game::logic() {
    Key playerAction = input->getKey();
    switch (playerAction) {
        case NO_KEY: break;
        case ONE: break;
        case TWO: break;
        case THREE: break;
        case UP:
            compositor->movePlayer(-1, 0);
            break;
        case LEFT:
            compositor->movePlayer(0, -1);
            break;
        case DOWN:
            compositor->movePlayer(1, 0);
            break;
        case RIGHT:
            compositor->movePlayer(0, 1);
            break;
        case ENTER: break;
        case SPACE: break;
        case ESCAPE:
            pause();
            break;
    }
    if (iterationNumber % 2 == 0) running = compositor->moveEnemies();
}

void Game::pause() {
    int choice = menu->choiceMenu("pauseMenu");
    if (choice == 2) gameLoop();
    if (choice == 3) running = false;
}

void Game::gameOver() {
    int choice = menu->choiceMenu("gameOver");
    if (choice == 1) {
        running = true;
        gameLoop();
    }
}