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
TARGET_SOURCES (vengine INTERFACE ${PROJECT_SOURCE_DIR}/include/vengine/vulkan/vulkan.cpp)




###############################################################################
#                                   OPTIONS                                   #
###############################################################################
OPTION (BUILD_LOADER "Build loader" ON)




###############################################################################
#                                 DEPENDENCIES                                #
###############################################################################
ADD_SUBDIRECTORY (${PROJECT_SOURCE_DIR}/libs/Vulkan-Headers)
ADD_SUBDIRECTORY (${PROJECT_SOURCE_DIR}/libs/Vulkan-Loader)
IF (NOT BUILD_LOADER)
    FIND_PACKAGE (Vulkan REQUIRED)
ENDIF ()




###############################################################################
#                                 REQUIREMENTS                                #
###############################################################################
TARGET_COMPILE_FEATURES (vengine INTERFACE  cxx_alias_templates
                                            cxx_attributes
                                            cxx_constexpr
                                            cxx_enum_forward_declarations
                                            cxx_inline_namespaces
                                            cxx_noexcept
                                            cxx_nullptr
                                            cxx_static_assert
                                            cxx_std_17
                                            cxx_variadic_templates)




###############################################################################
#                                    FLAGS                                    #
###############################################################################
SET_PROPERTY (TARGET vengine PROPERTY INTERFACE_CMAKE_CXX_STANDARD 17)
SET_PROPERTY (TARGET vengine PROPERTY INTERFACE_CMAKE_CXX_STANDARD_REQUIRED ON)
SET_PROPERTY (TARGET vengine PROPERTY INTERFACE_CMAKE_CXX_EXTENSIONS OFF)
IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    TARGET_COMPILE_OPTIONS (vengine INTERFACE
                                    /MP
                                    /Wall
                                    /W4
                                    /WX
                                    /GR-
                                    /we4146
                                    /we4308
                                    /we4532
                                    /we4533
                                    /we4700
                                    /we4703
                                    /we4789
                                    /we4996
                                    /we34057
                                    /we34245
                                    /we34456
                                    /we34701
                                    /we34703)
ELSE ()
    TARGET_COMPILE_OPTIONS (vengine INTERFACE
                                    -Wall
                                    -Wextra
                                    -Werror
                                    -Wpedantic
                                    -fno-exceptions
                                    -fno-rtti
                                    -Wdouble-promotion
                                    -Wformat=2
                                    -Wformat-overflow=2
                                    -Wformat-signedness
                                    -Wformat-truncation=2
                                    -Wnull-dereference
                                    -Wimplicit-fallthrough=5
                                    -Wmisleading-indentation
                                    -Wmissing-include-dirs
                                    -Wparentheses
                                    -Wuninitialized
                                    -Winit-self
                                    -Wstrict-aliasing=1
                                    -Wstrict-overflow=5
                                    -Wstringop-overflow=4
                                    -Warray-bounds=2
                                    -Wtautological-compare
                                    -Wfloat-equal
                                    -Wshadow
                                    -Wvector-operation-performance
                                    -Weffc++
                                    -Wno-unknown-warning-option)
ENDIF ()




###############################################################################
#                                   LINKING                                   #
###############################################################################
TARGET_LINK_LIBRARIES (vengine INTERFACE Vulkan::Headers)
TARGET_LINK_LIBRARIES (vengine INTERFACE Vulkan::Vulkan)
