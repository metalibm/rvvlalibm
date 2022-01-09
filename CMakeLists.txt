cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(rvvlalibm VERSION 0.1)

add_library(rvvlalibm src/vla_exp2_double.c
                      src/vla_exp2_single.c
                      src/vla_exp_double.c
                      src/vla_exp_single.c
                      src/vla_log10_double.c
                      src/vla_log10_single.c
                      src/vla_log2_double.c
                      src/vla_log2_single.c
                      src/vla_log_double.c
                      src/vla_log_single.c)

target_include_directories(rvvlalibm PUBLIC
          "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
