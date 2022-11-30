//
// Created by Sayama on 30/11/2022.
//

#include "oe_window.hpp"
#include <vulkan/vulkan.hpp>
namespace OxymoreEngine {

    OEwindow::OEwindow(int width, int height, std::string name) :
    width(width),
    height(height),
    name(name) {
        initWindow();
    }

    OEwindow::~OEwindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void OEwindow::initWindow() {
        // Init GLFW
        glfwInit();

        // Telling GLFW that we don't want the OpenGL library
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        // Not handling resizable window for now.
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        // Init the window
        this->window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
    }

    bool OEwindow::shouldClose() {
        return glfwWindowShouldClose(window);
    }
} // OxymoreEngine
