#include <vengine.hpp>

int main ()
{
    const VkError error = vengine::initializeVulkan("TEST APP", VK_MAKE_VERSION(1, 0, 0));
    if (error)
        return error;
    vengine::destroyVulkan();
    return 0;
}