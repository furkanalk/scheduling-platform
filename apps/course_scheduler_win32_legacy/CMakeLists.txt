add_executable(course_scheduler_win32_legacy WIN32
    ${PROJECT_SOURCE_DIR}/courseSchedule.cpp
    ${PROJECT_SOURCE_DIR}/courseManagement.cpp
    ${PROJECT_SOURCE_DIR}/teacherManagement.cpp
    ${PROJECT_SOURCE_DIR}/roomManagement.cpp
    ${PROJECT_SOURCE_DIR}/handlers.cpp
    ${PROJECT_SOURCE_DIR}/user.cpp
    ${PROJECT_SOURCE_DIR}/schedule.cpp
    ${PROJECT_SOURCE_DIR}/SQLiteHandler.cpp
    ${PROJECT_SOURCE_DIR}/sqlite3.c
    ${PROJECT_SOURCE_DIR}/courseSchedule.rc
)

target_include_directories(course_scheduler_win32_legacy
    PRIVATE
        ${PROJECT_SOURCE_DIR}
)

target_compile_definitions(course_scheduler_win32_legacy PRIVATE
    UNICODE
    _UNICODE
)

# Intentionally do not force C++20 or strict conformance flags on the
# untouched legacy target yet. Its purpose during migration is to remain
# a buildable behavioral reference.
