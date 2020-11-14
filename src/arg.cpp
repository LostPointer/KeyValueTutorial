#include "arg.hpp"

#include "command.hpp"

Arg::Arg(const std::string& arg) : arg_(arg) {}

Value Arg::Get(std::map<std::string, Value>& storage) const {
  if (IsCommand()) {
    auto command = command::MakeCommand(arg_);
    return command->Execute(storage);
  } else {
    return arg_;
  }
}

bool Arg::IsCommand() const {
  if (arg_.find(" ") != std::string::npos) return true;
  return false;
}
