# pragma once

enum cellState {
    EMPTY,
    WALL,
    PLAYER,
    ENEMY,
    TREASURE
};

class Compositor {
    private:
        static const int ROWS = 25;
        static const int COLS = 50;
    public:
        cellState gameWorld[ROWS][COLS];
        Compositor();
};