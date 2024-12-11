#include "Compositor.hpp"

Compositor::Compositor() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((i == 0) || (j == 0)) {
                gameWorld[i][j] = WALL;
            }
            if ((i == ROWS) || (j == COLS)) {
                gameWorld[i][j] = WALL;
            }
        }
    }
}