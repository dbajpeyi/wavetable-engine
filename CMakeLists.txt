cmake_minimum_required(VERSION 3.0.0)
project(Synth)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# add_executable(example example.c wavetable.c oscillator.c)
# add_executable(sequencer sequencer.c wavetable.c oscillator.c)
add_executable(synth wavetable.c oscillator.c bindings.cpp)
set_target_properties(synth PROPERTIES LINK_FLAGS "--bind --post-js ../em-es6-module.js -fexceptions -sALLOW_MEMORY_GROWTH -sENVIRONMENT=shell -sSINGLE_FILE=1 -sWASM=1 -sWASM_ASYNC_COMPILATION=0")
