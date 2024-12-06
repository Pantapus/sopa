#pragma once

enum Key {
    NO_KEY,
    ENTER,
    ESCAPE,
    SPACE,
    ONE,
    TWO
};

class Input {
    public:
        Key getKey();
};