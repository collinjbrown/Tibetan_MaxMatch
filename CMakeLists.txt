cmake_minimum_required (VERSION 3.22)

project (tmm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

set(BASE_SRCS
    "src/data/dictionary.cpp"
    "src/data/dictionary.h"
    "src/data/maxmatch.cpp"
    "src/data/maxmatch.h"
    "src/utility/filehandling.cpp"
    "src/utility/filehandling.h"
    "src/utility/parse.cpp"
    "src/utility/parse.h"
    "src/utility/scrubber.cpp"
    "src/utility/scrubber.h"
    "src/main.cpp"
)

add_executable (tmm ${BASE_SRCS})

add_custom_target(copy_datasets
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_LIST_DIR}/copy-datasets.cmake
)

add_dependencies(tmm copy_datasets)