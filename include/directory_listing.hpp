#pragma once
#include <string>
#include <string_view>
#include <vector>

namespace bs {
std::vector<std::string> directoryListing(std::string_view directoryPath);
} // namespace bs
