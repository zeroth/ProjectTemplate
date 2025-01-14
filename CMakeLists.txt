cmake_minimum_required(VERSION 3.15)
project(MyProject 
    VERSION 1.0.0
    DESCRIPTION "A modular C++ project"
    LANGUAGES CXX
)

# Configure modern C++ standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build options
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
option(MYPROJECT_BUILD_TESTS "Build test suite" OFF)
option(MYPROJECT_ENABLE_INSTALL "Enable installation" ON)

# Include FetchContent
include(FetchContent)

# Add the library and application
add_subdirectory(lib)
add_subdirectory(app)

# Testing configuration
if(MYPROJECT_BUILD_TESTS)
    enable_testing()
    # Only fetch GTest if we're the main project
    if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
        FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG v1.14.0
        )
        # For Windows: Prevent overriding the parent project's compiler/linker settings
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(googletest)
    endif()
    add_subdirectory(tests)
endif()

# Only configure CPack if we're the main project
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND MYPROJECT_ENABLE_INSTALL)
    # CPack Configuration
    include(InstallRequiredSystemLibraries)
    set(CPACK_PACKAGE_VENDOR "Your Organization")
    set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_DESCRIPTION}")
    set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
    set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
    set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
    set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
    set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

    # Platform specific packaging
    if(WIN32)
        set(CPACK_GENERATOR "NSIS;ZIP")
        set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES64")
        set(CPACK_NSIS_PACKAGE_NAME "${PROJECT_NAME}")
        set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
    elseif(APPLE)
        set(CPACK_GENERATOR "DragNDrop;TGZ")
    else()
        set(CPACK_GENERATOR "DEB;TGZ")
        set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name <your.email@example.com>")
        set(CPACK_DEBIAN_PACKAGE_SECTION "devel")
    endif()

    include(CPack)
endif() 