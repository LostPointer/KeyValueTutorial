#pragma once

#include "command.hpp"

namespace command {

class SumCommand : public BaseCommand {
 public:
  SumCommand(const std::vector<Arg>& args);

  Value Execute(std::map<std::string, Value>& storage) override;
};

}  // namespace command
