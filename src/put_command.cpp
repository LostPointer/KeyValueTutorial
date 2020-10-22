#include "put_command.hpp"

#include <iostream>
#include <sstream>

namespace command {

PutCommand::PutCommand(const std::vector<std::string>& args) {
  if (args.size() < 2) {
    throw command::BadCommand("Bad arguments of command put");
  }

  key = args[0];
  value = args[1];
}

std::string PutCommand::Execute(std::map<std::string, std::string>& storage) {
  storage[key] = value;

  std::stringstream result;

  result << "Put in storage (key='" << key << "'"
         << "value='" << value << ")" << std::endl;
  return result.str();
}

}  // namespace command
