#pragma once
#include <string>
#include <string_view>
#include <vector>

namespace bs {
[[nodiscard]] std::vector<std::string> readBibFile(std::string_view bibFile);
} // namespace bs
