#pragma once
/**
 * @brief Definitions for all the variables declared with external linkage.
 * Please do not #include this file, otherwise the
 * ODR (One Definition Rule) will be broken.
 * @file vengine.cpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com>
 *         https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 15-08-2019
 */

#define VENGINE_ELIDE_API_FUNCTIONS
#include <vengine/api.hpp>

VkInstance vengine::vulkan::instance = nullptr;
VkPhysicalDevice vengine::vulkan::physicalDevice = nullptr;
