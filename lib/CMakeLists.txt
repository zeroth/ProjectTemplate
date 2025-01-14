add_library(mylib
    src/calculator.cpp
)

add_library(${PROJECT_NAME}::mylib ALIAS mylib)

# Generate export header for proper symbol visibility
include(GenerateExportHeader)
generate_export_header(mylib
    BASE_NAME MYLIB
    EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/mylib_export.hpp"
)

target_include_directories(mylib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Set up installation if enabled
if(MYPROJECT_ENABLE_INSTALL)
    include(CMakePackageConfigHelpers)
    
    # Generate the version file
    write_basic_package_version_file(
        "${PROJECT_NAME}ConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
    )

    # Install targets
    install(TARGETS mylib
        EXPORT ${PROJECT_NAME}Targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
    )

    # Install headers
    install(
        DIRECTORY include/
        DESTINATION include
    )

    # Install generated headers
    install(
        FILES "${CMAKE_CURRENT_BINARY_DIR}/mylib_export.hpp"
        DESTINATION include/mylib
    )

    # Install export targets
    install(
        EXPORT ${PROJECT_NAME}Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION lib/cmake/${PROJECT_NAME}
    )

    # Configure and install package config file
    configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        INSTALL_DESTINATION lib/cmake/${PROJECT_NAME}
    )

    install(
        FILES
            ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
            ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION lib/cmake/${PROJECT_NAME}
    )
endif() 