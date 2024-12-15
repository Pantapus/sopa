#include "Game.hpp"
#include "Menu.hpp"
#include <chrono>
#include <exception>
#include <synchapi.h>

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
    constexpr int desiredFramedelay = 1000 / 20; //max 20 fps
    auto lastTime = std::chrono::high_resolution_clock::now();

    try { compositor.setMap("map1"); } catch (const std::exception& e) {
        Sleep(1000);
        menu.error(e.what());
        running = false;
    }
    
    while(running) {
        render.update();
        logic();
        auto currentTime = std::chrono::high_resolution_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime).count();
        if (elapsedTime < desiredFramedelay) {
            Sleep(desiredFramedelay - elapsedTime);
        }
        lastTime = std::chrono::high_resolution_clock::now();
        auto totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(lastTime - currentTime).count() + elapsedTime;
        render.printMessageAt(std::to_string(1000 / totalTime), 0, 25);
    }
}

void Game::logic() {
    Key playerAction = input.getKey();
    switch (playerAction) {
        case NO_KEY: break;
        case ONE: break;
        case TWO: break;
        case THREE: break;
        case UP:
            compositor.movePlayer(-1, 0);
            break;
        case LEFT:
            compositor.movePlayer(0, -1);
            break;
        case DOWN:
            compositor.movePlayer(1, 0);
            break;
        case RIGHT:
            compositor.movePlayer(0, 1);
            break;
        case ENTER: break;
        case SPACE: break;
        case ESCAPE:
            pause();
            break;
    }
    compositor.moveEnemies();
}

void Game::pause() {
    int choice = menu.pauseMenu();
    if (choice == 2) running = false;
}