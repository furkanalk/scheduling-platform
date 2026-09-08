add_library(scheduling_core STATIC
    src/platform_info.cpp
)

target_include_directories(scheduling_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(scheduling_core PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(scheduling_core PRIVATE
        /W4
        /permissive-
        /Zc:__cplusplus
    )
endif()
