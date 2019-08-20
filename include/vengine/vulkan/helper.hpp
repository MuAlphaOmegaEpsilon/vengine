#pragma once
/**
 * @brief Helper functions collection.
 * @file helper.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com>
 *         https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 18-08-2019
 */


// Helper macro, never undefined
#ifndef RET_ON_ERR
    #define RET_ON_ERR(fnCall) if (const VkError e = fnCall; e) return e
#endif
// Namespace names shorteners
#define VE_VK vengine::vulkan
// Specifiers shorteners
#define INL inline
#define NX noexcept
#define ND [[nodiscard]]

namespace vengine::vulkan
{
    template <class T, class Fn, class ... Args>
    ND INL VkError autoEnumerate
                        (Fn vulkanFn,
                         T*& elements,
                         Args&&... args) NX;
}

template <class T, class Fn, class ... Args>
VkError VE_VK::autoEnumerate
                (Fn vulkanFn,
                 T*& elements,
                 Args&&... args) NX
{   using namespace VE_VK;
    RET_ON_ERR (vulkanFn (args ..., nullptr));
    return vulkanFn (args ..., elements);
}

#undef VE_VK
#undef INL
#undef NX
#undef ND
