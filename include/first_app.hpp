//
// Created by Sayama on 30/11/2022.
//

#pragma once

#include "oe_window.hpp"

class first_app {
public:
    static constexpr int WIDTH = 854;
    static constexpr int HEIGHT = 480;

    void run();
private:
    OxymoreEngine::OEwindow OEwindow {WIDTH, HEIGHT, "Vulkan Window"};
};
