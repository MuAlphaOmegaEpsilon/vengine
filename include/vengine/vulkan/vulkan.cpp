/**
 * @brief Definitions for all the variables declared with external linkage.
 * Please do not `#include` this file, otherwise the
 * ODR (One Definition Rule) will be broken.
 * @file vulkan.cpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com>
 *         https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 15-08-2019
 */

#define CONCAT(a, b) a ## b
#define DEFINE_VK_HANDLE(name)      \
    struct CONCAT(name, _T);        \
    using name = CONCAT(name, _T*)
// Forward declarations in case no <vulkan/vulkan.h> has been included before.
DEFINE_VK_HANDLE (VkInstance);
DEFINE_VK_HANDLE (VkPhysicalDevice);

namespace vengine::vulkan
{
    extern "C" VkInstance instance = nullptr;
    extern "C" VkPhysicalDevice physicalDevice = nullptr;
}
