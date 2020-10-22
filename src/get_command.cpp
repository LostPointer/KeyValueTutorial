#include "get_command.hpp"

#include <sstream>

namespace command {

GetCommand::GetCommand(const std::vector<std::string> &args) {
  if (args.size() < 1) {
    throw command::BadCommand(
        "Bad arguments of command get, need at least 1 argument");
  }

  key = args[0];
}

std::string GetCommand::Execute(std::map<std::string, std::string> &storage) {
  std::stringstream result;

  result << "Get from storage[" << key << "]: " << storage[key];
  return result.str();
}
}  // namespace command
