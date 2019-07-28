#pragma once
/**
 * @brief A C++17 Vulkan barebone engine. 
 * @file vengine.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com> https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 01-07-2019
 */

#include <vulkan/vulkan.h>

using VkError = VkResult;

namespace vengine
{
    constexpr VkAllocationCallbacks* allocator = nullptr;

    VkInstance vkInstance;

    VkError initializeVulkan (const char* appName, uint32_t appVersion);
    void destroyVulkan ();
}

VkError vengine::initializeVulkan (const char* appName, uint32_t appVersion)
{
    using namespace vengine;

    const VkApplicationInfo vkApplicationInfo = 
    {
        VkStructureType::VK_STRUCTURE_TYPE_APPLICATION_INFO,
        nullptr,
        appName, appVersion,
        "Vengine", VK_MAKE_VERSION (1, 0, 0),
        VK_API_VERSION_1_0
    };
    const VkInstanceCreateInfo vkInstanceCreationInfo = 
    {
        VkStructureType::VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        nullptr,
        VkFlags {},
        &vkApplicationInfo,
        0, nullptr,
        0, nullptr
    };
    return vkCreateInstance (&vkInstanceCreationInfo, allocator, &vkInstance);
}

void vengine::destroyVulkan ()
{
    // TODO: this could be accomplished by using std::unique_ptr custom
    // Deleter functionality
    using namespace vengine;
    vkDestroyInstance (vkInstance, allocator);
}

