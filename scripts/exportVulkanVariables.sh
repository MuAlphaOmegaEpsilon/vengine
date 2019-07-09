#!/bin/sh
set -euf

### CALL THIS SCRIPT FROM THE PROJECT ROOT FOLDER ###

### SCRIPT CORE ###
VULKAN_VERSION=1.1.108.0 && export VULKAN_VERSION

Vulkan_INCLUDE_DIR="$(pwd)/libs/Vulkan-Headers/include" && export Vulkan_INCLUDE_DIR

case "$(uname -s)" in
    Darwin) # osx
        MOLTENVK_DIR="$(pwd)/vulkansdk-macos-${VULKAN_VERSION}/MoltenVK" && export MOLTENVK_DIR
        ;;
    Linux) # linux
        Vulkan_LIBRARY="/usr/lib/x86_64-linux-gnu" && export Vulkan_LIBRARY
        # VULKAN_SDK="$(pwd)/vulkan-sdk/x86_64" && export VULKAN_SDK
        # Vulkan_LIBRARY="${VULKAN_SDK}/lib" && export Vulkan_LIBRARY
        # PATH="${VULKAN_SDK}/bin:$PATH" && export PATH
        # LD_LIBRARY_PATH="${VULKAN_SDK}/lib:${LD_LIBRARY_PATH:-}" && export LD_LIBRARY_PATH
        # VK_LAYER_PATH="${VULKAN_SDK}/etc/vulkan/explicit_layer.d" && export VK_LAYER_PATH
        ;;
    CYGWIN*|MINGW32*|MSYS*) # windows
        VULKAN_SDK="C:\\VulkanSDK\\${VULKAN_VERSION}" && export VULKAN_SDK
        ;;
esac
