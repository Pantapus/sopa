#include "Compositor.hpp"
#include "AStar.hpp"
#include "Agent.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

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
                    enemies.emplace_back(row, col);
                    break;
                case '$':
                    gameWorld[row][col] = TREASURE;
                    break;
                case 'O':
                    gameWorld[row][col] = HOME;
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

bool Compositor::movePlayer(int x, int y) {
    Position desiredPos((player->position.x + x), (player->position.y + y));
    if (gameWorld[desiredPos.x][desiredPos.y] == EMPTY || gameWorld[desiredPos.x][desiredPos.y] == HOME) {
        gameWorld[player->position.x][player->position.y] = standingOn;
        standingOn = gameWorld[desiredPos.x][desiredPos.y];
        
        player->MoveTo(desiredPos);
        gameWorld[desiredPos.x][desiredPos.y] = PLAYER;
    }
    return (standingOn == HOME && player->hasTreasure);
}

bool Compositor::moveEnemies() {
    for (Enemy& enemy : enemies) {
        std::vector<Position> path = aStar(enemy.position, player->position, gameWorld);
        if (!path.empty()) {
            Position nextStep = path[0];
            if (gameWorld[nextStep.x][nextStep.y] == EMPTY) {
                gameWorld[enemy.position.x][enemy.position.y] = EMPTY;
                enemy.MoveTo(nextStep);
                gameWorld[nextStep.x][nextStep.y] = ENEMY;
            }
            if (gameWorld[nextStep.x][nextStep.y] == PLAYER) return false;
        }
    }
    return true;
}

void Compositor::attemptTheft() {
    if (gameWorld[player->position.x+1][player->position.y] == TREASURE) {
        gameWorld[player->position.x+1][player->position.y] = EMPTY;
        player->hasTreasure = true;
    }
    if (gameWorld[player->position.x-1][player->position.y] == TREASURE) {
        gameWorld[player->position.x-1][player->position.y] = EMPTY;
        player->hasTreasure = true;
    }
    if (gameWorld[player->position.x][player->position.y+1] == TREASURE) {
        gameWorld[player->position.x][player->position.y+1] = EMPTY;
        player->hasTreasure = true;
    }
    if (gameWorld[player->position.x][player->position.y-1] == TREASURE) {
        gameWorld[player->position.x][player->position.y-1] = EMPTY;
        player->hasTreasure = true;
    }
}