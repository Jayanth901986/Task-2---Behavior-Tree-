cmake_minimum_required(VERSION 3.10)
project(bt_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Allow the user to specify the install path of BehaviorTree.CPP
if(NOT BehaviorTreeV3_DIR)
    set(BehaviorTreeV3_DIR "/usr/local/lib/cmake/BehaviorTreeV3" CACHE PATH "BehaviorTree.CPP path")
endif()

# Find BehaviorTree.CPP
find_package(BehaviorTreeV3 REQUIRED)

# Build your action nodes as a shared library
add_library(actions SHARED src/actions.cpp)
target_link_libraries(actions PRIVATE BT::behaviortree_cpp_v3)

# Build the main executable
add_executable(main_bt src/main.cpp)
target_link_libraries(main_bt PRIVATE BT::behaviortree_cpp_v3)

# Ensure runtime library path is correct on Linux
set_target_properties(actions PROPERTIES
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH "$ORIGIN/../lib"
)

# Install targets
install(TARGETS main_bt actions
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
)

# Copy the XML file to the build directory
configure_file(tree.xml ${CMAKE_CURRENT_BINARY_DIR}/tree.xml COPYONLY)

