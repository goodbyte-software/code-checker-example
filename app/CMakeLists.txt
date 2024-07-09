cmake_minimum_required(VERSION 3.20.0)

set(CODECHECKER_ANALYZE_OPTS
    "--config;${CMAKE_SOURCE_DIR}/config/codechecker.yml;"
    "--skip;${CMAKE_SOURCE_DIR}/config/skip.codechecker"
    CACHE STRING "Code checker options")
set(CODECHECKER_EXPORT "html" CACHE STRING "Format of a generated report")

find_package(Zephyr-sdk REQUIRED)
find_package(Zephyr REQUIRED)
project(my_zephyr_app)

target_sources(app
    PRIVATE
        src/main.cpp
        src/worker.cpp
)
