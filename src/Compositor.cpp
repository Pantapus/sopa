#include "Compositor.hpp"
#include <fstream>
#include <sstream>
#include <string>

void Compositor::setMap(std::string asset) {
    std::ifstream file("assets/" + asset + ".txt");
    if (!file.is_open()) {
        throw std::runtime_error("Failed to load " + asset);
    }

    std::string line;
    size_t row = 0;
    while (std::getline(file, line) && row < ROWS) {
        std::stringstream ss(line);
        char ch;
        size_t col = 0;
        while (ss >> ch && col < COLS) {
            switch (ch) {
                case '.':
                    gameWorld[row][col] = EMPTY;
                    break;
                case '#':
                    gameWorld[row][col] = WALL;
                    break;
                case '@':
                    gameWorld[row][col] = PLAYER;
                    player = new Player(row, col);
                    break;
                case '8':
                    gameWorld[row][col] = ENEMY;
                    break;
                case '$':
                    gameWorld[row][col] = TREASURE;
                    break;
                default:
                    gameWorld[row][col] = UNKNOWN;
                    break;
            }
            ++col;
        }
        ++row;
    }
}

void Compositor::movePlayer(int x, int y) {
    Position desiredPos((player->position.x + x), (player->position.y + y));
    if (gameWorld[desiredPos.x][desiredPos.y] == EMPTY) {
        gameWorld[player->position.x][player->position.y] = EMPTY;
        player->MoveTo(desiredPos);
        gameWorld[desiredPos.x][desiredPos.y] = PLAYER;
    }
}