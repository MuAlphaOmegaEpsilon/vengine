#pragma once
/**
 * @brief Wrapper functions for vkEnumerate... ones.
 * @file enumerate.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com>
 *         https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 12-09-2019
 */

namespace vengine::vulkan::enumerate
{
    template <class T, class Fn, class ... Args>
    VkError autoEnumerate
                    (Fn vulkanFn,
                     ui32& count,
                     uptr <T []>& elements,
                     Args&&... args) NX;
}

extern "C" namespace vengine::vulkan::enumerate
{
    ND INL VkError getInstanceExtensionProperties
                    (ui32& count,
                     uptr <VkExtensionProperties []>& properties,
                     const char* extensionLayer) NX;
    ND INL VkError getInstanceLayerProperties
                    (ui32& count,
                     uptr <VkLayerProperties []>& properties) NX;
    ND INL VkError getInstanceVersion
                    (ui32& vulkanApiVersion) NX;
    ND INL VkError getPhysicalDeviceExtensionProperties
                    (ui32& count,
                     uptr <VkExtensionProperties []>& properties,
                     const char* extensionLayer,
                     VkPhysicalDevice device = physicalDevice) NX;
    ND INL VkError getPhysicalDeviceGroups
                    (ui32& count,
                     uptr <VkPhysicalDeviceGroupProperties []>& properties,
                     VkInstance inst = instance) NX;
    ND INL VkError getPhysicalDeviceLayerProperties
                    (ui32& count,
                     uptr <VkLayerProperties []>& properties,
                     VkPhysicalDevice device = physicalDevice) NX;
    ND INL VkError getPhysicalDevices
                    (ui32& count,
                     uptr <VkPhysicalDevice []>& devices) NX;
}



template <class T, class Fn, class ... Args>
VkError VE_VK_EN::autoEnumerate
				(Fn vulkanFn,
				 ui32& count,
				 uptr <T []>& elements,
				 Args&&... args) NX
{
	PROPAGATE (vulkanFn (args ..., &count, nullptr));
	elements = std::make_unique<T []>(count);
	return vulkanFn (args ..., &count, elements.get());
}

VkError VE_VK_EN::getPhysicalDevices
                (ui32& count,
                 uptr <VkPhysicalDevice []>& devices) NX
{
    return autoEnumerate (vkEnumeratePhysicalDevices,
                          count, devices, instance);
}
