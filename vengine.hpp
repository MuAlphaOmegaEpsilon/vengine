#pragma once
/**
 * @brief Vengine, a C++17 Vulkan barebone engine.
 * The main header file to include to use the Vengine library.
 * Here can be found definitions for functions declared in vengine/api.hpp.
 * @file vengine.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com>
 *         https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 01-07-2019
 */

#include <vulkan/vulkan.h>                     // Vulkan header
#include <vengine/vulkan/fwdecl_functions.hpp> // Public Vengine API
#include <algorithm>

// Namespace names shorteners
#define VE_VK vengine::vulkan
// Specifiers shorteners
#define INL inline
#define NX noexcept
#define ND [[nodiscard]]

// Throughout the code base vulkan errors are checked with `if(error)`
// assuming that a non-error condition is equal to zero.
static_assert (!VkResult::VK_SUCCESS, "VK_SUCCESS==0 assumption is invalid.");

namespace 
{
    template <class T, class Fn, class ... Args>
    VkError autoEnumerate
                    (Fn vulkanFn,
                    ui32& count,
                    std::unique_ptr<T []>& elements,
                    Args&&... args) NX
    {
        RET_ON_ERR (vulkanFn (args ..., &count, nullptr));
        elements = std::make_unique<T []>(count);
        return vulkanFn (args ..., &count, elements.get());
    }
}


void VE_VK::destroy () NX
{   using namespace VE_VK;
    vkDestroyInstance (instance, allocator);
}


VkError VE_VK::initialize
                (const char* appName,
                 ui32 appVersion) NX
{   using namespace VE_VK;
    const VkApplicationInfo appInfo = 
    {
        VkStructureType::VK_STRUCTURE_TYPE_APPLICATION_INFO,
        nullptr,
        appName, appVersion,
        "Vengine", VK_MAKE_VERSION (1, 0, 0),
        VK_API_VERSION_1_0
    };
    const VkInstanceCreateInfo instancingInfo = 
    {
        VkStructureType::VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        nullptr,
        VkFlags {},
        &appInfo,
        0, nullptr,
        0, nullptr
    };
    return vkCreateInstance (&instancingInfo, allocator, &instance);
}

VkError VE_VK::getPhysicalDevices
                (ui32& count,
                 VkPhysicalDevice*& devices) NX
{   using namespace VE_VK;
    return autoEnumerate (vkEnumeratePhysicalDevices,
                          devices, instance, &count);
}

#undef VE_VK
#undef INL
#undef NX
#undef ND
