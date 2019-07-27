cmake_minimum_required(VERSION 3.8)
project(CPPExampleBot LANGUAGES CXX)

add_subdirectory(RLBotCPP)

add_executable(CPPExampleBot main.cc examplebot.cc examplebot.h)
target_link_libraries(CPPExampleBot RLBotCPP)
target_include_directories(CPPExampleBot PRIVATE RLBotCPP/inc RLBotCPP/lib/inc)
target_compile_features(CPPExampleBot PRIVATE cxx_std_17)

# Copy interface dll to output folder
add_custom_command(TARGET  CPPExampleBot POST_BUILD
    COMMAND python ${PROJECT_SOURCE_DIR}/dlls/copy-dlls.py)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_custom_command(TARGET CPPExampleBot POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/dlls/RLBot_Core_Interface.dll"
        $<TARGET_FILE_DIR:CPPExampleBot>)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    add_custom_command(TARGET CPPExampleBot POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/dlls/RLBot_Core_Interface_32.dll"
        $<TARGET_FILE_DIR:CPPExampleBot>)
endif() 

# Copy port config to output folder
add_custom_command(TARGET CPPExampleBot POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/port.cfg"
        $<TARGET_FILE_DIR:CPPExampleBot>)