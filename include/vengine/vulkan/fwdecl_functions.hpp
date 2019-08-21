#pragma once
/**
 * @brief Forward declarations of the public Vengine API.
 * This file also includes `fwdecl_variables.hpp` as well as `stdint.h`.
 * @file fwdecl_functions.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com>
 *         https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 20-08-2019
 */

#include <vengine/vulkan/fwdecl_variables.hpp> // Needs fwd declared variables
#include <stdint.h>
using ui8 = uint8_t;
using ui16 = uint16_t;
using ui32 = uint32_t;
using ui64 = uint64_t;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

// Declaration shorteners
#define DEFINE_VK_HANDLE(name) struct name##_T; using name = name##_T*
// Namespace names shorteners
#define VE_VK vengine::vulkan
// Specifiers shorteners
#define INL inline
#define NX noexcept
#define ND [[nodiscard]]

// Local substitute enum in case the real VkResult is missing
extern "C" enum __VkResult : i32;

// Forward declarations
#ifndef VULKAN_H_
    using VkError = __VkResult;
    DEFINE_VK_HANDLE (VkExtensionProperties);
    DEFINE_VK_HANDLE (VkLayerProperties);
    DEFINE_VK_HANDLE (VkPhysicalDeviceGroupProperties);
#else
    using VkError = VkResult;
    static_assert (sizeof (__VkResult) == sizeof (VkResult),
                   "VkError doesn't alias correctly VkResult \
                    since sizes don't match.");
#endif

template <class T> using Compare = bool(&)(const T&, const T&);

extern "C" namespace vengine::vulkan
{
    ND INL bool defaultCompare
                        (const VkPhysicalDevice& a,
                         const VkPhysicalDevice& b) NX;
    ND INL bool isSuitable
                        (const VkPhysicalDevice&) NX;
    INL void destroy () NX;
    ND INL VkError getInstanceExtensionProperties
                        (ui32& count,
                         VkExtensionProperties& properties,
                         const char* extensionLayer) NX;
    ND INL VkError getInstanceLayerProperties
                        (ui32& count,
                         VkLayerProperties& properties) NX;
    ND INL VkError getInstanceVersion
                        (ui32& vulkanApiVersion) NX;
    ND INL VkError getPhysicalDeviceExtensionProperties
                        (ui32& count,
                         VkExtensionProperties& properties,
                         const char* extensionLayer,
                         VkPhysicalDevice device = physicalDevice) NX;
    ND INL VkError getPhysicalDeviceGroups
                        (ui32& count,
                         VkPhysicalDeviceGroupProperties& properties,
                         VkInstance inst = instance) NX;
    ND INL VkError getPhysicalDeviceLayerProperties
                        (ui32& count,
                         VkLayerProperties& properties,
                         VkPhysicalDevice device = physicalDevice) NX;
    ND INL VkError getPhysicalDevices
                        (ui32& count,
                         VkPhysicalDevice*& devices) NX;
    ND INL VkError initialize
                        (const char* appName,
                         ui32 appVersion) NX;
    ND INL VkError pickPhysicalDevice
                        (Compare<VkPhysicalDevice> = defaultCompare) NX;
}

#undef DEFINE_VK_HANDLE
#undef VE_VK
#undef INL
#undef NX
#undef ND
