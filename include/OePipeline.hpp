//
// Created by Sayama on 30/11/2022.
//

#pragma once

#include <string>
#include <vector>
#include "OeDevice.hpp"

namespace OxymoreEngine {
    // This is not part of the OePipeline class, so we can easily configure the pipeline
    //  as we want to.
    struct PipelineConfigInfo {
        VkViewport viewport;
        VkRect2D scissor;
        VkPipelineViewportStateCreateInfo viewportInfo;
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
        VkPipelineRasterizationStateCreateInfo rasterizationInfo;
        VkPipelineMultisampleStateCreateInfo multisampleInfo;
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
        VkPipelineColorBlendStateCreateInfo colorBlendInfo;
        VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
        VkPipelineLayout pipelineLayout = nullptr;
        VkRenderPass renderPass = nullptr;
        uint32_t subpass = 0;    };

    class OePipeline {
    public:
        OePipeline(
                OeDevice& device,
                const std::string& vertFilePath,
                const std::string& fragFilePath,
                const PipelineConfigInfo& configInfo);
        ~OePipeline() {};

        // removing the copy constructor to avoid copy of object with pointer reference as it can cause problems
        OePipeline(const OePipeline&) = delete;
        void operator=(const OePipeline&) = delete;

        static PipelineConfigInfo defaultPipelineConfig(uint32_t width, uint32_t height);
    private:
        // Even if it can be considered unsafe, we have a reference to the device
        //  as the Pipeline CANNOT exist without a device.s
        OeDevice& oeDevice;
        VkPipeline graphicPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;

        static std::vector<char> readFile(const std::string& filePath);

        void createGraphicsPipeline(const std::string& vertFilePath,const std::string& fragFilePath, const PipelineConfigInfo& configInfo);

        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);
    };

} // OxymoreEngine
