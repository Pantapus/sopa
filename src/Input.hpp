#pragma once

enum Key {
    NO_KEY,
    ONE,
    TWO,
    THREE,
    UP,
    LEFT,
    DOWN,
    RIGHT,
    ENTER,
    ESCAPE
};

class Input {
    public:
        Key getKey();
};