cmake_minimum_required(VERSION 3.5)
project(basic_agent_ST)

set(CMAKE_CXX_STANDARD 11)

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
	${CMAKE_SOURCE_DIR}/../Clothoids/lib/dll
	${CMAKE_SOURCE_DIR}/../Clothoids/lib3rd/dll
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
)


target_link_libraries(basic_agent agent_lib ${lib_ws32})
target_link_libraries(basic_agent libClothoids_linux.so ${lib_ws32})
target_link_libraries(basic_agent libquarticRootsFlocke_linux.so ${lib_ws32})
target_link_libraries(basic_agent libUtils_linux.so ${lib_ws32})
target_link_libraries(basic_agent ${CMAKE_DL_LIBS})


target_compile_options(basic_agent
        PUBLIC -DNOT_INLINED -DSERVER
)

set_target_properties(basic_agent PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${AGENT_FOLDER})
# ------------------------------------------------------------------------------------