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

extern "C" enum VkResult_fwdecl : i32;
#ifndef VULKAN_H_
using VkError = VkResult_fwdecl;
#else
static_assert (sizeof (VkResult_fwdecl) == sizeof (VkResult),
               "VkError doesn't alias correctly VkResult since sizes don't \
               match.");
using VkError = VkResult;
#endif
template <class T> using compare = bool (*)(const T, const T);

extern "C" namespace vengine::vulkan
{
    ND INL VkError initialize (const char* appName, ui32 appVersion) NX;
    ND INL VkError pickPhysicalDevice () NX;
    INL void destroy () NX;
}
#endif

#include <vengine/MACROS_UNDEFS.hpp>
