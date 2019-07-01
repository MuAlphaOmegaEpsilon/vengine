/**
 * @brief A C++17 Vulkan barebone engine. 
 * @file vengine.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com> https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 01-07-2019
 */

#include <assert.h>
#include <vulkan/vulkan.h>

#ifndef VENGINE_HPP
#define VENGINE_HPP

namespace vengine
{
    constexpr VkAllocationCallbacks* allocator = nullptr;

    VkInstance vkInstance;

    bool initializeVulkan (const char* appName, uint32_t appVersion);
    void destroyVulkan ();
}

bool vengine::initializeVulkan (const char* appName, uint32_t appVersion)
{
    using namespace vengine;

    const VkApplicationInfo vkApplicationInfo = 
    {
        VkStructureType::VK_STRUCTURE_TYPE_APPLICATION_INFO,
        nullptr,
        appName,
        appVersion,
        "Vengine",
        VK_MAKE_VERSION (1, 0, 0),
        VK_API_VERSION_1_1
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
    assert (vkCreateInstance (&vkInstanceCreationInfo, allocator, &vkInstance) == VkResult::VK_SUCCESS);
}

void vengine::destroyVulkan ()
{
    // TODO: this could be accomplished by using std::unique_ptr custom
    // Deleter functionality
    using namespace vengine;
    vkDestroyInstance (vkInstance, allocator);
}

#endif