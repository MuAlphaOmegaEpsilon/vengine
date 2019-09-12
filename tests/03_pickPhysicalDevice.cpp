#include <vengine.hpp>

int main ()
{
    // The PROPAGATE macro avoids to manually write some boilerplate to check if
    // an error occurred and to eventually return it.
    PROPAGATE (vengine::vulkan::initialize("myApp", VK_MAKE_VERSION(1, 0, 0)));
    PROPAGATE (vengine::vulkan::pickPhysicalDevice());
    
    vengine::vulkan::destroy();
    return 0;
}
