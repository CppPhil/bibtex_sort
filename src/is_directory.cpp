#include <cstring>

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "is_directory.hpp"

namespace bs {
bool isDirectory(std::string_view stringView)
{
  struct stat buf;
  std::memset(&buf, 0, sizeof(buf));
  const int statusCode{stat(stringView.data(), &buf)};

  if (statusCode == -1) { return false; }

  return S_ISDIR(buf.st_mode);
}
} // namespace bs
