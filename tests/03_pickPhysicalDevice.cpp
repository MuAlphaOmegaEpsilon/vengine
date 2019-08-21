#include <vengine.hpp>

int main ()
{
    // The RET_ON_ERR macro avoids to manually write some boilerplate to check if
    // an error occurred and to eventually return it.
    RET_ON_ERR (vengine::vulkan::initialize("myApp", VK_MAKE_VERSION(1, 0, 0)));
    RET_ON_ERR (vengine::vulkan::pickPhysicalDevice());
    
    vengine::vulkan::destroy();
    return 0;
}
