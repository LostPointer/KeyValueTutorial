#include "arg.hpp"

#include <iostream>

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

int Arg::ToInt() const {
  try {
    if (arg_.find(".") != std::string::npos)
      throw BadConvert("Can't convert to double");
    return std::stoi(arg_);
  } catch (const std::exception&) {
    throw BadConvert("Can't convert to int");
  }
}

double Arg::ToDouble() const {
  try {
    return std::stod(arg_);
  } catch (const std::exception&) {
    throw BadConvert("Can't convert to double");
  }
}

bool Arg::IsCommand() const {
  if (arg_.find(" ") != std::string::npos) return true;
  return false;
}
