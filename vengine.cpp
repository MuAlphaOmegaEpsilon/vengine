// This macro is similar to the one found in vulkan_core.h
#define VK_DEFINE_HANDLE(object) struct object##_T; using object = object##_T*;

VK_DEFINE_HANDLE(VkInstance)
VK_DEFINE_HANDLE(VkPhysicalDevice)

namespace vengine::vulkan
{
    extern "C" VkInstance instance;
    extern "C" VkPhysicalDevice physicalDevice;
}

VkInstance vengine::vulkan::instance = nullptr;
VkPhysicalDevice vengine::vulkan::physicalDevice = nullptr;
