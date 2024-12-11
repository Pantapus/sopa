# pragma once

#include <array>

enum cellState {
    EMPTY,
    WALL,
    PLAYER,
    ENEMY,
    TREASURE
};

class Compositor { 
    public:
        static const int ROWS = 10;
        static const int COLS = 20;
        std::array<std::array<cellState, COLS>, ROWS> gameWorld;
        Compositor();
};