#pragma once

#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

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
  BaseCommand() = default;
  virtual ~BaseCommand(){};
  virtual std::string Execute(std::map<std::string, std::string>& storage) = 0;
};

std::unique_ptr<BaseCommand> MakeCommand(const std::string& command_string);

}  // namespace command
