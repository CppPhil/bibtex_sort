#pragma once
#include <string>
#include <string_view>
#include <vector>

namespace bs {
[[nodiscard]] bool writeBibFile(
  const std::vector<std::string>& bibEntries,
  std::string_view                filePath);
} // namespace bs
