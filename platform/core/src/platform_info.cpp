#include "scheduling/core/platform_info.h"

namespace scheduling::core {

std::string_view platform_name() noexcept {
    return "Constraint-Based Scheduling & Optimization Platform";
}

std::string_view platform_version() noexcept {
    return "0.2.0";
}

} // namespace scheduling::core
