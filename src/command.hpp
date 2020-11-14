#pragma once

#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "arg.hpp"
#include "value.hpp"

namespace command {

class CommandError : public std::runtime_error {
 public:
  using std::runtime_error::runtime_error;
};

class UnknownCommand : public CommandError {
 public:
  using CommandError::CommandError;
};

class BadCommand : public CommandError {
 public:
  using CommandError::CommandError;
};

class BaseCommand {
 public:
  BaseCommand(const std::vector<Arg>& args) : args_(args){};
  virtual ~BaseCommand(){};
  virtual Value Execute(std::map<std::string, Value>& storage) = 0;

 protected:
  std::vector<Arg> args_;
};

std::unique_ptr<BaseCommand> MakeCommand(const std::string& command_string);

}  // namespace command
