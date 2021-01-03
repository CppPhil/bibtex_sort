#include <fstream>
#include <regex>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "fix_vert.hpp"

namespace bs {
namespace {
[[nodiscard]] std::vector<std::string> readLines(std::string_view filePath)
{
  std::ifstream ifs{std::string{filePath}};

  if (!ifs) {
    throw std::logic_error{"Could not open " + std::string{filePath}};
  }

  std::vector<std::string> result{};

  for (std::string lineBuffer{}; std::getline(ifs, lineBuffer);) {
    result.push_back(std::move(lineBuffer));
  }

  if (ifs.bad()) {
    throw std::logic_error{
      "Bad bit was set with file: " + std::string{filePath}};
  }

  return result;
}

[[nodiscard]] bool writeLines(
  const std::vector<std::string>& lines,
  std::string_view                filePath)
{
  std::ofstream ofs{
    std::string{filePath}, std::ios_base::out | std::ios_base::trunc};

  if (!ofs) { return false; }

  for (const std::string& line : lines) { ofs << line << '\n'; }

  ofs << '\n';

  return static_cast<bool>(ofs);
}
} // namespace

bool fixVert(std::string_view filePath)
{
  try {
    std::vector<std::string> lines{readLines(filePath)};

    for (std::string& line : lines) {
      line = std::regex_replace(line, std::regex{R"(\\vert\{\})"}, "|");
    }

    if (!writeLines(lines, filePath)) { return false; }
  }
  catch (const std::logic_error& ex) {
    (void)ex;
    return false;
  }

  return true;
}
} // namespace bs
