#include <fstream>

#include "write_bib_file.hpp"

namespace bs {
bool writeBibFile(
  const std::vector<std::string>& bibEntries,
  std::string_view                filePath)
{
  std::ofstream ofs{
    std::string{filePath}, std::ios_base::out | std::ios_base::trunc};

  if (!ofs) { return false; }

  ofs << "% Encoding: UTF-8\n";

  if (!ofs) { return false; }

  for (const std::string& entry : bibEntries) { ofs << entry; }

  return static_cast<bool>(ofs);
}
} // namespace bs
