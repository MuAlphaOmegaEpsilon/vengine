#include <vengine.hpp>

int main ()
{
    // The PROPAGATE macro avoids to manually write some boilerplate to check if
    // an error occurred and to eventually return it.
    PROPAGATE (vengine::vulkan::initialize("myApp", VK_MAKE_VERSION(1, 0, 0)));
    ui32 count = 0;
    std::unique_ptr <VkPhysicalDevice []> devices;
    // After this call, both count and devices will be filled with data
    PROPAGATE (vengine::vulkan::enumerate::getPhysicalDevices(count, devices));

    vengine::vulkan::destroy();
    return 0;
}
