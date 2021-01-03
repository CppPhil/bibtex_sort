#include <cstring>

#include <algorithm>

#include "bib_files.hpp"

namespace bs {
std::vector<std::string> bibFiles(std::string_view filePath)
{
  static constexpr std::size_t extensionLength{4U};

  std::vector<std::string> listing{directoryListing(filePath)};

  listing.erase(
    std::remove_if(
      listing.begin(),
      listing.end(),
      [](const std::string& entry) {
        if (entry.size() < extensionLength) { return true; }
        const char* const ptr{entry.data() + entry.size() - extensionLength};
        return std::strcmp(ptr, ".bib") != 0;
      }),
    listing.end());

  return listing;
}
} // namespace bs
