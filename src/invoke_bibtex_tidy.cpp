#include <cstdlib>

#include <string>

#include <sys/wait.h>

#include "invoke_bibtex_tidy.hpp"

namespace bs {
bool invokeBibtexTidy(std::string_view filePath)
{
  const std::string command{"bibtex-tidy " + std::string{filePath}};

  const int statusCode{std::system(command.c_str())};

  return WEXITSTATUS(statusCode) == 0;
}
} // namespace bs
