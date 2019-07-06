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
        wget "${LUNARG_URL}"/macos/vulkansdk-macos-"${VK_VERSION}".tar.gz 
        tar xf vulkansdk-macos-"${VK_VERSION}".tar.gz
        mv "${VK_VERSION}"/ vulkan-sdk/
        .vulkan-sdk/install_vulkan.py
        ;;
    Linux) # linux
        wget "${LUNARG_URL}"/linux/vulkansdk-linux-"${VK_VERSION}".tar.gz 
        tar xf vulkansdk-linux-"${VK_VERSION}".tar.gz
        mv "${VK_VERSION}"/ vulkan-sdk/
        cd vulkan-sdk
        chmod +x setup-env.sh
        ./setup-env.sh
        ;;
    CYGWIN*|MINGW32*|MSYS*) # windows
        wget "${LUNARG_URL}"/windows/VulkanSDK-"${VK_VERSION}"-Installer.exe
        VulkanSDK-"${VK_VERSION}"-Installer.exe /S
        ;;
    *)
        return 1
        ;;
esac
