#include <fstream>
#include <stdexcept>

#include "read_bib_file.hpp"

namespace bs {
std::vector<std::string> readBibFile(std::string_view bibFile)
{
  std::vector<std::string> result{};

  std::ifstream ifs{std::string{bibFile}};

  if (!ifs) {
    throw std::logic_error{
      "readBibFile: couldn't open \"" + std::string{bibFile}
      + "\" for reading."};
  }

  std::string currentBuffer{};
  for (std::string lineBuf{}; std::getline(ifs, lineBuf);) {
    if (lineBuf == "% Encoding: UTF-8") { continue; }

    currentBuffer += lineBuf + "\n";

    if (lineBuf == "}") {
      result.push_back(currentBuffer);
      currentBuffer = "";
    }
  }

  return result;
}
} // namespace bs
