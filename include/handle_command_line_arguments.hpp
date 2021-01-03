#pragma once
#include <optional>
#include <string>

namespace bs {
std::optional<std::string> handleCommandLineArguments(int argc, char** argv);
} // namespace bs
