###############################################################################
#                                CMAKE VERSION                                #
###############################################################################
CMAKE_MINIMUM_REQUIRED (VERSION 3.11.4)




###############################################################################
#                                   PROJECT                                   #
###############################################################################
PROJECT (vengine_tests VERSION 1.0.0 LANGUAGES CXX)




###############################################################################
#                            LIBRARIES INCLUSION                              #
###############################################################################
ADD_SUBDIRECTORY (${PROJECT_SOURCE_DIR}/.. ${PROJECT_SOURCE_DIR}/build/vengine)




###############################################################################
#                                    TESTS                                    #
###############################################################################
INCLUDE (CTest)

ADD_EXECUTABLE (test_initializeVulkan test_initializeVulkan.cpp)
TARGET_LINK_LIBRARIES (test_initializeVulkan PUBLIC vengine)
ADD_TEST (initializeVulkan test_initializeVulkan)


