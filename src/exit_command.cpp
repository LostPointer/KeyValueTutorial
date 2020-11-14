#include "exit_command.hpp"

#include <iostream>

namespace command {

ExitCommand::ExitCommand() : BaseCommand({}) {}

Value ExitCommand::Execute(
    [[maybe_unused]] std::map<std::string, Value> &storage) {
  exit(0);
  return Value("exit");
}
}  // namespace command
