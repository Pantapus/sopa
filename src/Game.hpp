#pragma once

class Game {
    public:
        Game();
    private:
        void gameLoop();
        void logic();
        void pause();
        void gameOver();
};