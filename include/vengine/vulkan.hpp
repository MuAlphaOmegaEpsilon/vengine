#pragma once
/**
 * @brief Vulkan API exposed by vengine.
 * @file vulkan.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com>
 *         https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 12-09-2019
 */

#define VE_VK vengine::vulkan
#define VE_VK_DE vengine::vulkan::defaults
#define VE_VK_EN vengine::vulkan::enumerate
#define INL inline
#define NX noexcept
#define ND [[nodiscard]]

using VkError = VkResult;
// Vulkan errors are checked with `if(error)` throughout the codebase,
// assuming that a non-error condition is equal to zero.
static_assert (!VkResult::VK_SUCCESS, "VK_SUCCESS==0 assumption is invalid.");
// A macro useful to propagate errors back up to the caller on true value.
#define PROPAGATE(fnCall) if (const auto e = fnCall; e) return e

namespace vengine::vulkan
{
    extern "C" VkInstance instance;
    extern "C" VkPhysicalDevice physicalDevice;
    constexpr VkAllocationCallbacks* allocator = nullptr;
}

#include <vengine/vulkan/defaults.hpp>
#include <vengine/vulkan/enumerate.hpp>

extern "C" namespace vengine::vulkan
{   using namespace VE_VK::defaults;
    using namespace vengine::algorithm;
    INL void destroy () NX;
    ND INL VkError initialize
                        (const char* appName,
                         ui32 appVersion) NX;
    ND INL VkError pickPhysicalDevice
                        (UnaryPred<VkPhysicalDevice> = isDeviceSuitable,
                         UnaryScore<VkPhysicalDevice> = scoreDevice) NX;
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

VkError VE_VK::pickPhysicalDevice
                (UnaryPred<VkPhysicalDevice> filter,
                 UnaryScore<VkPhysicalDevice> score) NX
{   using namespace VE_VK::enumerate;
    using namespace vengine::algorithm;
	uint32_t count = 0;
    uptr <VkPhysicalDevice []> devices;
    PROPAGATE (getPhysicalDevices(count, devices));

    VkPhysicalDevice* ptr = devices.get();
    physicalDevice = *max(ptr, ptr + count, score, filter);
    return VK_SUCCESS;
}

#undef VE_VK
#undef VE_VK_DE
#undef VE_VK_EN
#undef INL
#undef NX
#undef ND
