#include <algorithm>
#include <stdexcept>

#include <dirent.h>
#include <sys/types.h>

#include "directory_listing.hpp"
#include "is_directory.hpp"

namespace bs {
std::vector<std::string> directoryListing(std::string_view directoryPath)
{
  using namespace std::string_literals;

  if (!isDirectory(directoryPath)) {
    throw std::logic_error{
      "directoryListing: "s + std::string{directoryPath}
      + " is not a directory"};
  }

  std::vector<std::string> result{};

  DIR* dir{opendir(directoryPath.data())};

  if (dir == nullptr) {
    throw std::logic_error{
      "directoryListing: Couldn't open "s + std::string{directoryPath}};
  }

  for (dirent* entry{nullptr}; (entry = readdir(dir)) != nullptr;) {
    result.push_back(
      std::string{directoryPath} + std::string{"/"} + entry->d_name);
  }

  if (closedir(dir) == EBADF) {
    throw std::logic_error{
      "directoryListing: Couldn't close "s + std::string{directoryPath}};
  }

  std::sort(result.begin(), result.end());
  return result;
}
} // namespace bs
