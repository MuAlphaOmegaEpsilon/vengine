// This macro is similar to the one found in vulkan_core.h
#define VK_DEFINE_HANDLE(object) struct object##_T; using object = object##_T*;

VK_DEFINE_HANDLE(VkInstance)
VK_DEFINE_HANDLE(VkPhysicalDevice)

namespace vengine::vulkan
{
    VkInstance instance = nullptr;
    VkPhysicalDevice physicalDevice = nullptr;
}