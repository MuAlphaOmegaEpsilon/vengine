###############################################################################
#                                CMAKE VERSION                                #
###############################################################################
CMAKE_MINIMUM_REQUIRED (VERSION 3.11.4)




###############################################################################
#                                   PROJECT                                   #
###############################################################################
PROJECT (vengine VERSION 1.0.0 LANGUAGES CXX DESCRIPTION "A C++17 Vulkan barebone engine.")
ADD_LIBRARY (vengine INTERFACE)
TARGET_INCLUDE_DIRECTORIES (vengine INTERFACE ${PROJECT_SOURCE_DIR})
TARGET_INCLUDE_DIRECTORIES (vengine INTERFACE ${PROJECT_SOURCE_DIR}/include)
TARGET_SOURCES (vengine INTERFACE ${PROJECT_SOURCE_DIR}/vengine.cpp)




###############################################################################
#                                 DEPENDENCIES                                #
###############################################################################
ADD_SUBDIRECTORY (${PROJECT_SOURCE_DIR}/libs/Vulkan-Headers)
IF (USE_LOCAL_VULKAN)
    ADD_SUBDIRECTORY (${PROJECT_SOURCE_DIR}/libs/Vulkan-Loader)
ELSE ()
    FIND_PACKAGE (Vulkan REQUIRED)
ENDIF ()




###############################################################################
#                                   LINKING                                   #
###############################################################################
TARGET_LINK_LIBRARIES (vengine INTERFACE Vulkan::Headers)
TARGET_LINK_LIBRARIES (vengine INTERFACE Vulkan::Vulkan)




###############################################################################
#                                   OPTIONS                                   #
###############################################################################
OPTION (USE_LOCAL_VULKAN "Use the Vulkan loader provided by this repository?" ON)
