#pragma once
/**
 * @brief Useful defaults functions and values for the Vulkan API exposed by
 * vengine.
 * @file defaults.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com>
 *         https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 12-09-2019
 */

extern "C" namespace vengine::vulkan::defaults
{
    ND INL ui32 scoreDevice
                    (const VkPhysicalDevice&) NX;
    ND INL bool isDeviceSuitable
                    (const VkPhysicalDevice&) NX;
}



ui32 VE_VK_DE::scoreDevice
                (const VkPhysicalDevice& device) NX
{
    VkPhysicalDeviceProperties properties;
	vkGetPhysicalDeviceProperties(device, &properties);
    // Devices with a discrete GPU have priority --> higher score
    switch (properties.deviceType)
    {
    case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:   return 1 << 3;
    case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:    return 1 << 2;
    case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU: return 1 << 1;
    case VK_PHYSICAL_DEVICE_TYPE_CPU:            return 1 << 0;
    case VK_PHYSICAL_DEVICE_TYPE_OTHER:          return 0;
    default:                                     return 0;
    }
}

bool VE_VK_DE::isDeviceSuitable
                (const VkPhysicalDevice& device) NX
{
    (void)(device);
    return true;
}
