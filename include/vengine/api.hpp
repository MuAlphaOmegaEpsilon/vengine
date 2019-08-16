#pragma once
/**
 * @brief The public API to use to directly interact with Vengine.
 * @file api.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com>
 *         https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 15-08-2019
 */

#include <vengine/MACROS_DEFS.hpp>

// Forward declarations for some types
DEFINE_VK_HANDLE (VkInstance);
DEFINE_VK_HANDLE (VkPhysicalDevice);
struct VkAllocationCallbacks;

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

using ui8 = uint8_t;
using ui16 = uint16_t;
using ui32 = uint32_t;
using ui64 = uint64_t;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using VkError = VkResult;
extern "C" namespace vengine::vulkan
{
    ND INL VkError initialize (const char* appName, uint32_t appVersion);
    ND INL VkError pickPhysicalDevice ();
    INL void destroy ();
}
#endif

#include <vengine/MACROS_UNDEFS.hpp>
