#pragma once
/**
 * @brief Forward declarations of the public Vengine global variables.
 * @file fwdecl_variables.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com>
 *         https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 20-08-2019
 */

// Declaration shorteners
#define DEFINE_VK_HANDLE(name) struct name##_T; using name = name##_T*
// Helper macro, never undefined
#ifndef RET_ON_ERR
    #define RET_ON_ERR(fnCall) if (const VkError e = fnCall; e) return e
#endif

// Forward declarations
#ifndef VULKAN_H_
    DEFINE_VK_HANDLE (VkInstance);
    DEFINE_VK_HANDLE (VkPhysicalDevice);
    struct VkAllocationCallbacks;
#endif

namespace vengine::vulkan
{
    extern "C" VkInstance instance;
    extern "C" VkPhysicalDevice physicalDevice;
    constexpr VkAllocationCallbacks* allocator = nullptr;
}

#undef DEFINE_VK_HANDLE
