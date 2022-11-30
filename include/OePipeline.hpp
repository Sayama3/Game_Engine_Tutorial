//
// Created by Sayama on 30/11/2022.
//

#pragma once

#include <string>
#include <vector>

namespace OxymoreEngine {

    class OePipeline {
    public:
        OePipeline(const std::string vertFilePath,const std::string fragFilePath);
    private:
        static std::vector<char> readFile(const std::string& filePath);

        void createGraphicsPipeline(const std::string vertFilePath,const std::string fragFilePath);
    };

} // OxymoreEngine
