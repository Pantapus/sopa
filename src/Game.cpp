#include "Game.hpp"
#include "Menu.hpp"
#include <chrono>
#include <exception>
#include <string>
#include <synchapi.h>
#include <thread>

Compositor* compositor;
ConsoleRender* render;
Input* input;
Menu* menu;
bool running = true;
bool win;
int iterationNumber = 0;

Game::Game() {
    gameLoop();
}

void Game::gameLoop() {    
    win = false;
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

    constexpr std::chrono::milliseconds desiredFramedelay(1000/20); 
    while(running) {
        auto lastTime = std::chrono::steady_clock::now();
        auto nextFrameTime = lastTime + desiredFramedelay;
        iterationNumber += 1;
        render->update();
        logic();
        std::this_thread::sleep_until(nextFrameTime);
        std::string fps = std::to_string(1000/(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - lastTime).count()));
        render->printMessageAt(fps, 0, 25);
    }
    gameOver();
}

void Game::logic() {
    Key playerAction = input->getKey();
    switch (playerAction) {
        case NO_KEY: break;
        case ONE:
            compositor->attemptTheft();
            break;
        case TWO: break;
        case THREE: break;
        case UP:
            win = compositor->movePlayer(-1, 0);
            break;
        case LEFT:
            win = compositor->movePlayer(0, -1);
            break;
        case DOWN:
            win = compositor->movePlayer(1, 0);
            break;
        case RIGHT:
            win = compositor->movePlayer(0, 1);
            break;
        case ENTER: break;
        case SPACE: break;
        case ESCAPE:
            pause();
            break;
    }
    running = !win;
    if (iterationNumber % 2 == 0) running = compositor->moveEnemies();
}

void Game::pause() {
    int choice = menu->choiceMenu("pauseMenu");
    if (choice == 2) gameLoop();
    if (choice == 3) running = false;
}

void Game::gameOver() {
    std::string whatMenu = win ? "winMenu" : "lossMenu";
    int choice = menu->choiceMenu(whatMenu);
    if (choice == 1) {
        running = true;
        gameLoop();
    }
}