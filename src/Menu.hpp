#pragma once
#include "ConsoleRender.hpp"
#include "Input.hpp"

class Menu {
    public:
        Menu(ConsoleRender& render, Input& input);
        void startMenu();
        int pauseMenu();
    private: 
        ConsoleRender& render;
        Input& input;
};