###############################################################################
#                                CMAKE VERSION                                #
###############################################################################
CMAKE_MINIMUM_REQUIRED (VERSION 3.11.4)




###############################################################################
#                                   PROJECT                                   #
###############################################################################
PROJECT (vengine VERSION 1.0.0 LANGUAGES CXX DESCRIPTION "A C++17 Vulkan barebone engine.")




###############################################################################
#                                  LIBRARY                                    #
###############################################################################
ADD_LIBRARY (vengine INTERFACE)




###############################################################################
#                                  HEADERS                                    #
###############################################################################
TARGET_INCLUDE_DIRECTORIES (vengine INTERFACE ${PROJECT_SOURCE_DIR})

ADD_SUBDIRECTORY (${CMAKE_CURRENT_SOURCE_DIR}/libs/Vulkan-Headers)
SET (BUILD_WSI_XCB_SUPPORT OFF CACHE BOOL "Don't build XCB WSI support" FORCE)
SET (BUILD_WSI_XLIB_SUPPORT OFF CACHE BOOL "Don't build Xlib WSI support" FORCE)
SET (BUILD_WSI_WAYLAND_SUPPORT OFF CACHE BOOL "Don't build Wayland WSI support" FORCE)
ADD_SUBDIRECTORY (${CMAKE_CURRENT_SOURCE_DIR}/libs/Vulkan-Loader)
TARGET_LINK_LIBRARIES (vengine INTERFACE Vulkan::Vulkan)
