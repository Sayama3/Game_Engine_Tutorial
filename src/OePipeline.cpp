//
// Created by Sayama on 30/11/2022.
//

#include "OePipeline.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace OxymoreEngine {
    std::vector<char> OePipeline::readFile(const std::string &filePath) {
        std::ifstream file{filePath, std::ios::ate | std::ios::binary};
        if (!file.is_open()){
            throw std::runtime_error("Failed to open file: " + filePath);
        }
        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        // Go back to start
        file.seekg(0);

        // Store data in buffer
        file.read(buffer.data(), fileSize);
        file.close();
        return buffer;
    }

    OePipeline::OePipeline(const std::string vertFilePath, const std::string fragFilePath) {
        createGraphicsPipeline(vertFilePath, fragFilePath);
    }

    void OePipeline::createGraphicsPipeline(const std::string vertFilePath, const std::string fragFilePath) {
        auto vertCode = readFile(vertFilePath);
        auto fragCode = readFile(fragFilePath);

        std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
        std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
    }
} // OxymoreEngine