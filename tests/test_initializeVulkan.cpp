#include <vengine.hpp>

int main ()
{
    const VkError error = vengine::vulkan::initialize("TEST APP", VK_MAKE_VERSION(1, 0, 0));
    if (error)
        return error;
    vengine::vulkan::destroy();
    return 0;
}