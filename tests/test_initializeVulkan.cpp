#include <vengine.hpp>

int main ()
{
    if (vengine::initializeVulkan("TEST APP", VK_MAKE_VERSION(1, 0, 0)))
        return 1;
    vengine::destroyVulkan();
    return 0;
}