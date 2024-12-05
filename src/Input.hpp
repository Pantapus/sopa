#pragma once

enum Key {
    NO_KEY,
    ENTER,
    ESCAPE,
    SPACE
};

class Input {
    public:
        Key getKey();
};