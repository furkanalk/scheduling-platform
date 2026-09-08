add_library(solver_genetic INTERFACE)

target_link_libraries(solver_genetic
    INTERFACE
        scheduling_core
)

target_compile_features(solver_genetic INTERFACE cxx_std_20)
