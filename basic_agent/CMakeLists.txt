cmake_minimum_required(VERSION 3.5)
project(basic_agent_ST)

set(CMAKE_CXX_STANDARD 17) # C++11 -> C++17

include(lib/basic.cmake)

include_directories(
        matlab/
        matlab/codegen/lib/primitives/
        lib
        log
        rrt
        ${CMAKE_SOURCE_DIR}/../Clothoids/src
        ${CMAKE_SOURCE_DIR}/../Clothoids/lib/include
        ${CMAKE_SOURCE_DIR}/../Clothoids/lib3rd/include
)


link_directories(
        lib
	${CMAKE_SOURCE_DIR}/../Clothoids/lib/lib
	${CMAKE_SOURCE_DIR}/../Clothoids/lib3rd/lib
)

# ------------------------------- basic agent ------------------------------------
add_executable(basic_agent
        log/screen_print.c
        log/logvars.cc
        matlab/codegen/lib/primitives/primitives.c
        matlab/codegen/lib/primitives/rtGetInf.c
        matlab/codegen/lib/primitives/rtGetNaN.c
        matlab/codegen/lib/primitives/rt_nonfinite.c
        starting_point.cc
        rrt/rrt_star.cpp
        rrt/rrt_support.cpp
        rrt/rrt_clothoid.cpp
)

target_link_libraries(basic_agent agent_lib ${lib_ws32} ${CMAKE_DL_LIBS})
target_link_libraries(basic_agent
    agent_lib
    Clothoids_mingw
    quarticRootsFlocke_mingw
    UtilsLite_mingw
    ${lib_ws32}
    ${CMAKE_DL_LIBS}
)

target_compile_options(basic_agent
        PUBLIC -DNOT_INLINED -DSERVER
)

set_target_properties(basic_agent PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${AGENT_FOLDER})
# ------------------------------------------------------------------------------------