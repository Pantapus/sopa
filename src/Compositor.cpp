#include "Compositor.hpp"

Compositor::Compositor() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameWorld[i][j] = EMPTY;
            if ((i == 0) || (j == 0)) {
                gameWorld[i][j] = WALL;
            }
            if ((i == (ROWS - 1)) || (j == (COLS - 1))) {
                gameWorld[i][j] = WALL;
            }
        }
    }
}