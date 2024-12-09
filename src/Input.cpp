#include "Input.hpp"
#include <windows.h>

Key Input::getKey() {
    for (int i = 0x31; i <= 0x32; i++) { // hex för 0-9 = 0x30-0x39
        if (GetAsyncKeyState(i) & 0x8000) {
            switch(i) {
                case 0x31:
                    return ONE;
                case 0x32:
                    return TWO;
                case 0x33:
                    return THREE;
            }
        }
    }
    if (GetAsyncKeyState('W') & 0x8000) {
        return UP;
    }
    if (GetAsyncKeyState('A') & 0x8000) {
        return LEFT;
    }
    if (GetAsyncKeyState('S') & 0x8000) {
        return DOWN;
    }
    if (GetAsyncKeyState('D') & 0x8000) {
        return RIGHT;
    }
    if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
        return ENTER;
    }
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
        return ESCAPE;
    }
    return NO_KEY;
}