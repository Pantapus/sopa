#pragma once

#include <string>
class Game {
    public:
        Game();
    private:
        void gameLoop();
        void logic();
        void pause();
        void gameOver();
        std::string selectMap();
};