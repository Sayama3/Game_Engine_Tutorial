//
// Created by Sayama on 30/11/2022.
//

#include "OeWindow.hpp"
#include <stdexcept>


namespace OxymoreEngine {

    OeWindow::OeWindow(int width, int height, std::string name) :
    width(width),
    height(height),
    name(name) {
        initWindow();
    }

    OeWindow::~OeWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void OeWindow::initWindow() {
        // Init GLFW
        glfwInit();

        // Telling GLFW that we don't want the OpenGL library
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        // Not handling resizable window for now.
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        // Init the window
        this->window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
    }

    bool OeWindow::shouldClose() {
        return glfwWindowShouldClose(window);
    }

    void OeWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if(glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create window surface.");
        }
    }
} // OxymoreEngine
