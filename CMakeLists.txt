project(grumat)

cmake_minimum_required(VERSION 3.20)

include(FetchContent)

set(CMAKE_CXX_STANDARD 14)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.10.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_compile_options(-Wall -Wextra -pedantic)

file(GLOB SOURCES
    src/asset_indexer.h
    src/pre_fixed_bond.cpp
    src/pre_fixed_bond.h
    src/indexer.h
    src/simple_exponential_indexer.h
    src/simple_exponential_indexer.cpp
)

file(GLOB TEST_FILES
    src/pre_fixed_bond_test.cpp
    src/simple_exponential_indexer_test.cpp
)

add_executable(grumat 
    main.cpp
    ${SOURCES}
)

enable_testing()

add_executable(tests 
    ${SOURCES}
    ${TEST_FILES}
)

target_link_libraries(tests gtest_main)

include(GoogleTest)

gtest_discover_tests(tests)

