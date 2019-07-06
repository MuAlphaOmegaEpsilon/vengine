#!/bin/sh
set -euf

### NAVIGATE TO THE ROOT FOLDER ###
cd "$(dirname "$0")/.."

### COLORING SCHEME ###
ORANGE=$(tput setaf 3)
NOCOLOR=$(tput sgr0)

### SCRIPT CORE ###
printf "%sINSTALLING VULKAN-SDK%s\\n" "${ORANGE}" "${NOCOLOR}"
VULKAN_VERSION=1.1.108.0 && export VULKAN_VERSION
LUNARG_URL=https://sdk.lunarg.com/sdk/download/"${VULKAN_VERSION}"

case "$(uname -s)" in
    Darwin) # osx
        wget -q "${LUNARG_URL}"/mac/vulkansdk-macos-"${VULKAN_VERSION}".tar.gz
        tar xf vulkansdk-macos-"${VULKAN_VERSION}".tar.gz
        mv vulkansdk-macos-"${VULKAN_VERSION}"/ vulkan-sdk/
        cd vulkan-sdk
        ./install_vulkan.py
        ;;
    Linux) # linux
        wget -q "${LUNARG_URL}"/linux/vulkansdk-linux-"${VULKAN_VERSION}".tar.gz
        tar xf vulkansdk-linux-"${VULKAN_VERSION}".tar.gz
        mv "${VULKAN_VERSION}"/ vulkan-sdk/
        VULKAN_SDK="$(pwd)/vulkan-sdk/x86_64" && export VULKAN_SDK
        Vulkan_LIBRARY="${VULKAN_SDK}/lib" && export Vulkan_LIBRARY
        Vulkan_INCLUDE_DIR="${VULKAN_SDK}/include" && export Vulkan_INCLUDE_DIR
        PATH="${VULKAN_SDK}/bin:$PATH" && export PATH
        LD_LIBRARY_PATH="${VULKAN_SDK}/lib:${LD_LIBRARY_PATH:-}" && export LD_LIBRARY_PATH
        VK_LAYER_PATH="${VULKAN_SDK}/etc/vulkan/explicit_layer.d" && export VK_LAYER_PATH
        echo "${VULKAN_SDK}"
        ;;
    CYGWIN*|MINGW32*|MSYS*) # windows
        wget -q "${LUNARG_URL}"/windows/VulkanSDK-"${VULKAN_VERSION}"-Installer.exe
        ./VulkanSDK-"${VULKAN_VERSION}"-Installer.exe /S
        VULKAN_SDK="C:\\VulkanSDK\\${VULKAN_VERSION}" && export VULKAN_SDK
        ;;
    *)
        return 1
        ;;
esac
