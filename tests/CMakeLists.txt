###############################################################################
#                                CMAKE VERSION                                #
###############################################################################
CMAKE_MINIMUM_REQUIRED (VERSION 3.11.4)




###############################################################################
#                                   PROJECT                                   #
###############################################################################
PROJECT (vengine_tests VERSION 1.0.0 LANGUAGES CXX)
SET (CMAKE_CXX_STANDARD 17)
SET (CMAKE_CXX_STANDARD_REQUIRED ON)
SET (CMAKE_CXX_EXTENSIONS OFF)





###############################################################################
#                            LIBRARIES INCLUSION                              #
###############################################################################
ADD_SUBDIRECTORY (${PROJECT_SOURCE_DIR}/.. ${PROJECT_SOURCE_DIR}/build/vengine)




###############################################################################
#                                    TESTS                                    #
###############################################################################
INCLUDE (CTest)

ADD_EXECUTABLE (01_initializeVulkan 01_initializeVulkan.cpp)
ADD_EXECUTABLE (02_getPhysicalDevices 02_getPhysicalDevices.cpp)

TARGET_LINK_LIBRARIES (01_initializeVulkan PUBLIC vengine)
TARGET_LINK_LIBRARIES (02_getPhysicalDevices PUBLIC vengine)

ADD_TEST ([01]initializeVulkan 01_initializeVulkan)
ADD_TEST ([02]getPhysicalDevices 02_getPhysicalDevices)


