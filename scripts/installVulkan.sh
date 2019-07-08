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
        wget ""${LUNARG_URL}"/mac/vulkansdk-macos-"${VULKAN_VERSION}".tar.gz"
        tar xf vulkansdk-macos-"${VULKAN_VERSION}".tar.gz
        cd vulkansdk-macos-"${VULKAN_VERSION}" && ./install_vulkan.py
        ;;
    Linux) # linux
        wget ""${LUNARG_URL}"/linux/vulkansdk-linux-"${VULKAN_VERSION}".tar.gz"
        tar xf vulkansdk-linux-"${VULKAN_VERSION}".tar.gz
        mv "${VULKAN_VERSION}"/ vulkan-sdk/
        ;;
    CYGWIN*|MINGW32*|MSYS*) # windows
        wget ""${LUNARG_URL}"/windows/vulkan-sdk.exe?Human=false" -O vulkan-sdk.exe
        .\vulkan-sdk.exe /S
        ;;
    *)
        return 1
        ;;
esac
