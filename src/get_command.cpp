#include "get_command.hpp"

#include <iostream>
#include <sstream>

namespace command {

GetCommand::GetCommand(const std::vector<Arg> &args) : BaseCommand(args) {
  if (args_.size() < 1) {
    throw command::BadCommand(
        "Bad arguments of command get, need at least 1 argument");
  }
}

Value GetCommand::Execute(std::map<std::string, Value> &storage) {
  return storage[args_[0].Get(storage).ToString()];
}
}  // namespace command
