//
// Created by Sayama on 30/11/2022.
//
#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace OxymoreEngine {

    class OEwindow {
    public:
        /// Constructor of the Oxymore Engine Window.
        /// \param width : Window Width
        /// \param height : Window Height
        /// \param name : Window Name
        OEwindow(int width, int height, std::string name);

        /// Destructor of the Oxymore Engine.
        ~OEwindow();

        // Removing Copy constructors.
        // If we copy the constructor and have two objects with the same reference to GLFWwindow, if one of them is destroyed,
        //  the last one would be left with a pointer to a destroyed object.
        OEwindow(const OEwindow &) = delete;
        OEwindow &operator=(const OEwindow &) = delete;

        /// Whether this window should be closing or not.
        /// \return True if the window should close.
        bool shouldClose();

    private:
        void initWindow();

        const int width;
        const int height;

        std::string name;
        GLFWwindow* window;
    };

} // OxymoreEngine
