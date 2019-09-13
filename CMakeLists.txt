cmake_minimum_required(VERSION 3.8)
project(CPPExampleBot LANGUAGES CXX)

add_subdirectory(RLBotCPP)

add_executable(CPPExampleBot main.cc examplebot.cc examplebot.h)
target_include_directories(CPPExampleBot PRIVATE RLBotCPP/inc RLBotCPP/lib/inc)

if (UNIX)
    target_link_libraries(CPPExampleBot RLBotCPP pthread)
else (UNIX)
    target_link_libraries(CPPExampleBot RLBotCPP)
endif (UNIX)

target_compile_features(CPPExampleBot PRIVATE cxx_std_17)

# Copy port config to output folder
add_custom_command(TARGET CPPExampleBot POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/port.cfg"
        $<TARGET_FILE_DIR:CPPExampleBot>)