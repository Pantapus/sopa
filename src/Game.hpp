#pragma once

class Game {
    public:
        Game();
    private:
        void gameLoop();
        void draw();
        void playerInput();
        void logic();
};