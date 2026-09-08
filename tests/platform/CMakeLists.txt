add_executable(platform_smoke_test
    platform_smoke_test.cpp
)

target_link_libraries(platform_smoke_test
    PRIVATE
        scheduling_core
        academic_domain
)

target_compile_features(platform_smoke_test PRIVATE cxx_std_20)

add_test(
    NAME platform_smoke_test
    COMMAND platform_smoke_test
)
