#pragma once

#include <vector>
#include "Compositor.hpp"

struct Node {
    int x;
    int y;
    int g;
    int h;
    int f() const {return g + h;}
    bool operator<(const Node& other) const {return f() > other.f();}
};

std::vector<Position> aStar(const Position& start,
    const Position& target,
    const std::array<std::array<cellState, Compositor::COLS>, Compositor::ROWS>& gameWorld);