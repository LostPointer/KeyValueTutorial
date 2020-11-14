#include "put_command.hpp"

#include <iostream>
#include <sstream>

namespace command {

PutCommand::PutCommand(const std::vector<Arg>& args) : BaseCommand(args) {
  if (args.size() < 2) {
    throw command::BadCommand("Bad arguments of command put");
  }
}

Value PutCommand::Execute(std::map<std::string, Value>& storage) {
  auto key = args_[0].Get(storage);
  auto value = args_[1].Get(storage);
  storage[key.ToString()] = value;

  return value;
}

}  // namespace command
