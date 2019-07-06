#!/bin/sh
set -euf

### NAVIGATE TO THE ROOT FOLDER ###
cd "$(dirname "$0")/.."

### COLORING SCHEME ###
ORANGE=$(tput setaf 3)
NOCOLOR=$(tput sgr0)

### SCRIPT CORE ###
VULKAN_VERSION=1.1.108.0 && export VULKAN_VERSION

case "$(uname -s)" in
    Darwin) # osx
        ;;
    Linux) # linux
        VULKAN_SDK="$(pwd)/vulkan-sdk/x86_64" && export VULKAN_SDK
        Vulkan_LIBRARY="${VULKAN_SDK}/lib" && export Vulkan_LIBRARY
        Vulkan_INCLUDE_DIR="${VULKAN_SDK}/include" && export Vulkan_INCLUDE_DIR
        PATH="${VULKAN_SDK}/bin:$PATH" && export PATH
        LD_LIBRARY_PATH="${VULKAN_SDK}/lib:${LD_LIBRARY_PATH:-}" && export LD_LIBRARY_PATH
        VK_LAYER_PATH="${VULKAN_SDK}/etc/vulkan/explicit_layer.d" && export VK_LAYER_PATH
        ;;
    CYGWIN*|MINGW32*|MSYS*) # windows
        VULKAN_SDK="C:\\VulkanSDK\\${VULKAN_VERSION}" && export VULKAN_SDK
        ;;
esac