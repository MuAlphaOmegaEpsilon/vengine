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
#                                 REQUIREMENTS                                #
###############################################################################
TARGET_COMPILE_FEATURES (vengine INTERFACE cxx_alias_templates)
TARGET_COMPILE_FEATURES (vengine INTERFACE cxx_attributes)
TARGET_COMPILE_FEATURES (vengine INTERFACE cxx_constexpr)
TARGET_COMPILE_FEATURES (vengine INTERFACE cxx_enum_forward_declarations)
TARGET_COMPILE_FEATURES (vengine INTERFACE cxx_inline_namespaces)
TARGET_COMPILE_FEATURES (vengine INTERFACE cxx_noexcept)
TARGET_COMPILE_FEATURES (vengine INTERFACE cxx_nullptr)
TARGET_COMPILE_FEATURES (vengine INTERFACE cxx_relaxed_constexpr)
TARGET_COMPILE_FEATURES (vengine INTERFACE cxx_static_assert)
TARGET_COMPILE_FEATURES (vengine INTERFACE cxx_std_17)
TARGET_COMPILE_FEATURES (vengine INTERFACE cxx_variadic_templates)




###############################################################################
#                                    FLAGS                                    #
###############################################################################
SET_PROPERTY (TARGET vengine PROPERTY INTERFACE_CMAKE_CXX_STANDARD 17)
SET_PROPERTY (TARGET vengine PROPERTY INTERFACE_CMAKE_CXX_STANDARD_REQUIRED ON)
SET_PROPERTY (TARGET vengine PROPERTY INTERFACE_CMAKE_CXX_EXTENSIONS OFF)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wall)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wextra)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Werror)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wpedantic)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -fno-exceptions)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -fno-rtti)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wdouble-promotion)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wformat=2)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wformat-overflow=2)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wformat-signedness)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wformat-truncation=2)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wnull-dereference)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wimplicit-fallthrough=5)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wmisleading-indentation)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wmissing-include-dirs)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wmultistatement-macros)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wparentheses)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wuninitialized)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Winit-self)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wstrict-aliasing=1)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wstrict-overflow=5)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wstringop-overflow=4)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Warray-bounds=2)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wtautological-compare)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wfloat-equal)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wshadow)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Wvector-operation-performance)
TARGET_COMPILE_OPTIONS (vengine INTERFACE -Weffc++)
TARGET_COMPILE_OPTIONS (vengine INTERFACE --analyze-auto)





###############################################################################
#                                   LINKING                                   #
###############################################################################
TARGET_LINK_LIBRARIES (vengine INTERFACE Vulkan::Headers)
TARGET_LINK_LIBRARIES (vengine INTERFACE Vulkan::Vulkan)




###############################################################################
#                                   OPTIONS                                   #
###############################################################################
OPTION (USE_LOCAL_VULKAN "Use the Vulkan loader provided by this repository?" ON)
