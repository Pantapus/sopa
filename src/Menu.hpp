#pragma once
#include "ConsoleRender.hpp"
#include "Input.hpp"

class Menu {
    public:
        Menu(ConsoleRender& render, Input& input);
        void startMenu();
        int pauseMenu();
        void error(const char*);
    private: 
        ConsoleRender& render;
        Input& input;
};