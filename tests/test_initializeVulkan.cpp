#include <vengine.hpp>

int main ()
{
    // The RET_ERR macro avoids to manually write some boilerplate to check if
    // an error occurred and to eventually return it.
    RET_ERR (vengine::vulkan::initialize("myApp", VK_MAKE_VERSION(1, 0, 0)));
    vengine::vulkan::destroy();
    return 0;
}