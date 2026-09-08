add_library(academic_domain STATIC
    src/domain_info.cpp
)

target_include_directories(academic_domain
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(academic_domain
    PUBLIC
        scheduling_core
)

target_compile_features(academic_domain PUBLIC cxx_std_23)

if(MSVC)
    target_compile_options(academic_domain PRIVATE
        /W4
        /permissive-
        /Zc:__cplusplus
    )
endif()
