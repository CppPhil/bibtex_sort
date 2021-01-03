#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "bib_files.hpp"
#include "fix_vert.hpp"
#include "handle_command_line_arguments.hpp"
#include "invoke_bibtex_tidy.hpp"
#include "read_bib_file.hpp"
#include "write_bib_file.hpp"

int main(int argc, char* argv[])
{
  try {
    const std::optional<std::string> commandLineParsingResult{
      bs::handleCommandLineArguments(argc, argv)};

    if (!commandLineParsingResult.has_value()) {
      std::cerr
        << "No directory path was given as the sole command line argument.\n";
      return EXIT_FAILURE;
    }

    const std::vector<std::string> bibFiles{
      bs::bibFiles(commandLineParsingResult.value())};

    for (const std::string& bibFile : bibFiles) {
      if (!bs::invokeBibtexTidy(bibFile)) {
        std::cerr << "Couldn't invoke bibtex-tidy for file \"" << bibFile
                  << "\"!\n";
        return EXIT_FAILURE;
      }

      if (!bs::fixVert(bibFile)) {
        std::cerr << "Couldn't fix \\vert{} for file \"" << bibFile << "\"!\n";
        return EXIT_FAILURE;
      }

      std::vector<std::string> bibEntries{bs::readBibFile(bibFile)};
      std::sort(bibEntries.begin(), bibEntries.end());

      if (!bs::writeBibFile(bibEntries, bibFile)) {
        std::cerr << "Couldn't write sorted bib entries to \"" << bibFile
                  << "\"!\n";
        return EXIT_FAILURE;
      }
    }
  }
  catch (const std::logic_error& ex) {
    std::cerr << "std::logic_error: " << ex.what() << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
