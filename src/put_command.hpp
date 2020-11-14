#pragma once

#include "command.hpp"

namespace command {

class PutCommand : public BaseCommand {
 public:
  PutCommand(const std::vector<Arg>& args);

  Value Execute(std::map<std::string, Value>& storage) override;
};
}  // namespace command
