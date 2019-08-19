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
#                                   OPTIONS                                   #
###############################################################################
OPTION (USE_LOCAL_VULKAN "Use the Vulkan loader provided by this repository?" ON)




###############################################################################
#                                DEPENDENCIES                                 #
###############################################################################
ADD_SUBDIRECTORY (${PROJECT_SOURCE_DIR}/libs/Vulkan-Headers)
TARGET_LINK_LIBRARIES (vengine INTERFACE Vulkan::Headers)

IF (USE_LOCAL_VULKAN)
    ADD_SUBDIRECTORY (${PROJECT_SOURCE_DIR}/libs/Vulkan-Loader)
ELSE ()
    FIND_PACKAGE (Vulkan REQUIRED)
ENDIF ()
TARGET_LINK_LIBRARIES (vengine INTERFACE Vulkan::Vulkan)




###############################################################################
#                                  HEADERS                                    #
###############################################################################
TARGET_INCLUDE_DIRECTORIES (vengine INTERFACE ${PROJECT_SOURCE_DIR})
TARGET_INCLUDE_DIRECTORIES (vengine INTERFACE ${PROJECT_SOURCE_DIR}/include)




###############################################################################
#                                  SOURCES                                    #
###############################################################################
TARGET_SOURCES (vengine INTERFACE ${PROJECT_SOURCE_DIR}/vengine.cpp)
