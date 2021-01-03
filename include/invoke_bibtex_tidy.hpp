#pragma once
#include <string_view>

namespace bs {
[[nodiscard]] bool invokeBibtexTidy(std::string_view filePath);
} // namespace bs
