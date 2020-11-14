#pragma once

#include "command.hpp"

namespace command {

class GetCommand : public BaseCommand {
 public:
  GetCommand(const std::vector<Arg>& args);

  Value Execute(std::map<std::string, Value>& storage) final;
};
}  // namespace command
