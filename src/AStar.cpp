#include "AStar.hpp"
#include <queue>
#include <unordered_map>

int heuristic(int x1, int y1, int x2, int y2) {
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

std::vector<Position> aStar(const Position &start,
                            const Position &target,
                            const std::array<std::array<cellState, 50>, 25> &gameWorld) {
    
    std::priority_queue<Node> openSet;
    std::unordered_map<int, Node> visited;

    auto toKey = [](int x, int y) { return x * 1000 + y; }; // Unique key for a grid cell

    openSet.push({start.x, start.y, 0, heuristic(start.x, start.y, target.x, target.y)});

    std::unordered_map<int, Position> cameFrom; // Path reconstruction

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        if (current.x == target.x && current.y == target.y) {
            // Reconstruct path
            std::vector<Position> path;
            Position step = {current.x, current.y};
            while (cameFrom.find(toKey(step.x, step.y)) != cameFrom.end()) {
                path.push_back(step);
                step = cameFrom[toKey(step.x, step.y)];
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        if (visited.count(toKey(current.x, current.y)))
            continue;

        visited[toKey(current.x, current.y)] = current;

        // Explore neighbors (4 cardinal directions)
        const std::vector<Position> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const Position& dir : directions) {
            int nx = current.x + dir.x;
            int ny = current.y + dir.y;

            if (nx < 0 || nx >= Compositor::ROWS || ny < 0 || ny >= Compositor::COLS || gameWorld[nx][ny] == WALL)
                continue;

            int newG = current.g + 1;
            int key = toKey(nx, ny);

            if (visited.count(key) && visited[key].g <= newG)
                continue;

            openSet.push({nx, ny, newG, heuristic(nx, ny, target.x, target.y)});
            cameFrom[key] = {current.x, current.y};
        }
    }
    return {};
}