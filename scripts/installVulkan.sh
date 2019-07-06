#!/bin/sh
set -euf

### NAVIGATE TO THE ROOT FOLDER ###
cd "$(dirname "$0")/.."

### COLORING SCHEME ###
ORANGE=$(tput setaf 3)
NOCOLOR=$(tput sgr0)

### SCRIPT CORE ###
printf "%sINSTALLING VULKAN-SDK%s\\n" "${ORANGE}" "${NOCOLOR}"
VK_VERSION=1.1.108.0
LUNARG_URL=https://sdk.lunarg.com/sdk/download/"${VK_VERSION}"

case "$(uname -s)" in
    Darwin) # osx
        wget -q "${LUNARG_URL}"/mac/vulkansdk-macos-"${VK_VERSION}".tar.gz
        tar xf vulkansdk-macos-"${VK_VERSION}".tar.gz
        mv vulkansdk-macos-"${VK_VERSION}"/ vulkan-sdk/
        cd vulkan-sdk
        ./install_vulkan.py
        ;;
    Linux) # linux
        wget -q "${LUNARG_URL}"/linux/vulkansdk-linux-"${VK_VERSION}".tar.gz
        tar xf vulkansdk-linux-"${VK_VERSION}".tar.gz
        mv "${VK_VERSION}"/ vulkan-sdk/
        VULKAN_SDK="$(pwd)/vulkan-sdk/x86_64" && export VULKAN_SDK
        VULKAN_LIBRARY="${VULKAN_SDK}/lib/libvulkan.so.${VK_VERSION}" && export VULKAN_LIBRARY
        VULKAN_INCLUDE_DIR="${VULKAN_SDK}/include" && export VULKAN_INCLUDE_DIR
        PATH="${VULKAN_SDK}/bin:$PATH" && export PATH
        LD_LIBRARY_PATH="${VULKAN_SDK}/lib:${LD_LIBRARY_PATH:-}" && export LD_LIBRARY_PATH
        VK_LAYER_PATH="${VULKAN_SDK}/etc/vulkan/explicit_layer.d" && export VK_LAYER_PATH
        echo "${VULKAN_SDK}"
        ;;
    CYGWIN*|MINGW32*|MSYS*) # windows
        DownloadFile "${LUNARG_URL}"/windows/VulkanSDK-"${VK_VERSION}"-Installer.exe -FileName vulkan.exe
        vulkan.exe /S
        ;;
    *)
        return 1
        ;;
esac
