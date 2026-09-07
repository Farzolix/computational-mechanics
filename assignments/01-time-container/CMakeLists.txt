add_executable(
    time_container
    tests/main.cpp
    src/Time.cpp
)

target_include_directories(
    time_container
    PRIVATE
    include
)