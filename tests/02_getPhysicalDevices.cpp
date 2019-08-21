#include <vengine.hpp>

int main ()
{
    // The RET_ON_ERR macro avoids to manually write some boilerplate to check if
    // an error occurred and to eventually return it.
    RET_ON_ERR (vengine::vulkan::initialize("myApp", VK_MAKE_VERSION(1, 0, 0)));
    ui32 count = 0;
    std::unique_ptr <VkPhysicalDevice []> devices;
    // After this call, both count and devices will be filled with data
    VkError e = vengine::vulkan::getPhysicalDevices(count, devices);
    // This is due to Travis CI missing valid Physical Devices, so lets skip it
    if (e && e != VK_ERROR_INITIALIZATION_FAILED)
        return e;

    vengine::vulkan::destroy();
    return 0;
}
