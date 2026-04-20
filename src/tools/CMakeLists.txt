# Additional CMake configuration file for building the command-line tools of 
# the supernovas library
#
# To invoke simply configure the cmake build in the supernovas directory.
#
# Author: Attila Kovacs

# ----------------------------------------------------------------------------
# Build the 'supernovas' library as a static OR as a shared lib.
# depending on BUILD_SHARED_LIBS

add_executable(iers-fetch iers-fetch.c)

target_include_directories(iers-fetch PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Link with math libs as necessary
target_link_libraries(iers_fetch PRIVATE core)
