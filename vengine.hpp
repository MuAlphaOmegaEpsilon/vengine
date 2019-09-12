#pragma once
/**
 * @brief Vengine, a C++17 Vulkan barebone engine.
 * The main header file to include to use the Vengine library.
 * @file vengine.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com>
 *         https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 01-07-2019
 */

#include <memory>
#include <stdint.h>

template <class T> 
using uptr = std::unique_ptr <T>;
template <class T> 
using sptr = std::shared_ptr <T>;
using ui8 = uint8_t;
using ui16 = uint16_t;
using ui32 = uint32_t;
using ui64 = uint64_t;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

#include <vengine/algorithm.hpp>

#include <vulkan/vulkan.h>    // Vulkan header
#include <vengine/vulkan.hpp> // Vengine customized Vulkan API
