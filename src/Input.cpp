#include "Input.hpp"
#include <windows.h>

Key Input::getKey() {
    if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
        return ENTER;
    }
    if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        return SPACE;
    }
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
        return ESCAPE;
    }
    return NO_KEY;
}