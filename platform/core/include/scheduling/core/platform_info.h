#pragma once

#include <string_view>

namespace scheduling::core {

[[nodiscard]] std::string_view platform_name() noexcept;
[[nodiscard]] std::string_view platform_version() noexcept;

} // namespace scheduling::core
