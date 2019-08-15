#pragma once
/**
 * @brief The public API to use to directly interact with Vengine.
 * @file api.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com>
 *         https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 15-08-2019
 */

// Forward declarations for some types
#define DEFINE_VK_HANDLE(name) struct name##_T; using name = name##_T*
DEFINE_VK_HANDLE (VkInstance);
DEFINE_VK_HANDLE (VkPhysicalDevice);
struct VkAllocationCallbacks;

// Shorteners MACROS
#define INL inline
#define ND [[nodiscard]]


// This section can be elided from the inclusion by a simple
// #define VENGINE_ELIDE_API_VARIABLES before the #include <vengine/api.hpp>
#ifndef VENGINE_ELIDE_API_VARIABLES
namespace vengine::vulkan
{
    extern "C" VkInstance instance;
    extern "C" VkPhysicalDevice physicalDevice;
    constexpr VkAllocationCallbacks* allocator = nullptr;
}
#endif


// This section can be elided from the inclusion by a simple 
// #define VENGINE_ELIDE_API_FUNCTIONS before the #include <vengine/api.hpp>
#ifndef VENGINE_ELIDE_API_FUNCTIONS
#include <stdint.h>
using VkError = VkResult;
extern "C" namespace vengine::vulkan
{
    ND INL VkError initialize (const char* appName, uint32_t appVersion);
    ND INL VkError pickPhysicalDevice ();
    INL void destroy ();
}
#endif


#undef ND
#undef INL
#undef DEFINE_VK_HANDLE
