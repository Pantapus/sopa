# pragma once

struct Position {
            int x;
            int y;
            Position() = default;
            Position(int x, int y) : x(x), y(y) {}
        };

class Agent {
    public:
        Position position;
        Agent(int x, int y) : position(x, y) {}
        void MoveTo(Position& position);
};

class Enemy : public Agent {
    public:
        Enemy(int x, int y) : Agent(x, y) {}
};

class Player : public Agent {
    public:
        Player(int x, int y) : Agent(x, y) {}
};