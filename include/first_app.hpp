//
// Created by Sayama on 30/11/2022.
//

#pragma once

#include "OeWindow.hpp"
#include "OePipeline.hpp"

class first_app {
public:
    static constexpr int WIDTH = 854;
    static constexpr int HEIGHT = 480;

    void run();
private:
    OxymoreEngine::OeWindow OeWindow {WIDTH, HEIGHT, "Vulkan Window"};
    OxymoreEngine::OePipeline OePipeline {"shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv"};
};
