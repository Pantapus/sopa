#pragma once

class Game {
    public:
        Game();
    private:
        void gameLoop();
        void draw();
        void logic();
        void pause();
};