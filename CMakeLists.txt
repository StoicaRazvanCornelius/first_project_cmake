#ensure a minimum required cmake version
cmake_minimum_required(VERSION 3.31.3)

#project(first_of_its_kind CXX)   
project(first_of_its_kind
        VERSION 1.0.0.0
        DESCRIPTION this-is-serious
        LANGUAGES CXX)

# Configure the file
configure_file(
    ${CMAKE_SOURCE_DIR}/include/config.h.in  # Input file
    ${CMAKE_BINARY_DIR}/config.h     # Output file
)        

# Add the output directory to the include path #this is global
#include_directories(${CMAKE_BINARY_DIR})

# Make glob Sources variable with all files .cpp from src
file(GLOB SOURCES "src/*.cpp")

#Make executable for project of type WIN32 with glob from sources
add_executable(project_executable WIN32 ${SOURCES})

#Add the output directory to the include path #this is target specific
target_include_directories(project_executable PUBLIC
                           "${CMAKE_BINARY_DIR}"
                           )
set_target_properties(project_executable PROPERTIES  # this ensures project code is compliant with standard 
    CXX_STANDARD 11          # Specify the minimum C++ standard (e.g., 17, 20, 23)
    CXX_STANDARD_REQUIRED ON # Enforce at least this standard
    CXX_EXTENSIONS OFF       # Avoid compiler-specific extensions (optional)
)
target_compile_features(project_executable PRIVATE cxx_std_11) #this makes sure that said things specified up exists so that compiler can use that standard
