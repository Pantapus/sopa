# pragma once

#include <array>
#include <string>
#include "Input.hpp"

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
        void movePlayer(Key& dir);
};