#include <iostream>
#include <string_view>

#include "handle_command_line_arguments.hpp"
#include "is_directory.hpp"

namespace bs {
std::optional<std::string> handleCommandLineArguments(int argc, char** argv)
{
  constexpr int expectedArgumentCount{2};

  if (argc != expectedArgumentCount) {
    std::cerr << __PRETTY_FUNCTION__ << ": argc is " << argc
              << ", but it should've been " << expectedArgumentCount << '\n';
    return std::nullopt;
  }

  const std::string_view directoryPath{argv[1]};

  if (!isDirectory(directoryPath)) {
    std::cerr << __PRETTY_FUNCTION__ << ": " << directoryPath
              << " is not a directory!\n";
    return std::nullopt;
  }

  return std::string{directoryPath};
}
} // namespace bs
