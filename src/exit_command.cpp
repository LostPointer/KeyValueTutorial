#include "exit_command.hpp"

#include <iostream>

namespace command {

ExitCommand::ExitCommand() {}

std::string ExitCommand::Execute([
    [maybe_unused]] std::map<std::string, std::string> &storage) {
  exit(0);
}
}  // namespace command
