# pragma once

#include <array>
#include <string>
#include <vector>
#include "Agent.hpp"

enum cellState : char {
    EMPTY = ' ',
    WALL = '#',
    PLAYER = '@',
    ENEMY = '8',
    TREASURE = '$',
    UNKNOWN = '?'
};

class Compositor { 
    public:
        static const int ROWS = 25;
        static const int COLS = 50;
        std::array<std::array<cellState, COLS>, ROWS> gameWorld;
        void setMap(std::string asset);
        void movePlayer(int x, int y);
        void moveEnemies();
    private:
        Player* player;
        std::vector<Enemy> enemies;
};