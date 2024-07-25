cmake_minimum_required(VERSION 3.10)
project(BookShopManagement)

# Set paths to dependencies and libraries
set(DEPENDENCIES_DIR "${CMAKE_SOURCE_DIR}/Dependencies")
set(LIB_DIR "${DEPENDENCIES_DIR}/lib")
set(INCLUDE_DIR "${DEPENDENCIES_DIR}/include")
set(INCLUDE_MINGW64_DIR "${DEPENDENCIES_DIR}/mingw64")

# Compiler flags
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories
include_directories(
    "${INCLUDE_DIR}"
    "${INCLUDE_DIR}/mysql"
    "${INCLUDE_MINGW64_DIR}/include"
    "${INCLUDE_MINGW64_DIR}/x86_64-w64-mingw32/include"
)

# Source files
set(SOURCES
    main.cpp
    Books.cpp
    Employees.cpp
    Members.cpp
    Purchases.cpp
    Sales.cpp
    Suppliers.cpp
)

# Executable
add_executable(BookShopManagement ${SOURCES})

# Link libraries
target_link_libraries(BookShopManagement
    "${LIB_DIR}/libmysql.dll"
    "${LIB_DIR}/libssl-3-x64.dll"
    "${LIB_DIR}/libcrypto-3-x64.dll"
)

# Copy libmysql.dll to output directory
add_custom_command(TARGET BookShopManagement POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${LIB_DIR}/libmysql.dll"
        "${LIB_DIR}/libssl-3-x64.dll"
        "${LIB_DIR}/libcrypto-3-x64.dll"
        $<TARGET_FILE_DIR:BookShopManagement>
)

# Set output directory for executable
set_target_properties(BookShopManagement PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)