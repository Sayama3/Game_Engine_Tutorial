//
// Created by Sayama on 30/11/2022.
//

#include "first_app.hpp"

void first_app::run() {
    while(!this->OeWindow.shouldClose()) {
        glfwPollEvents();
    }
}
