#pragma once

#include "command.hpp"

namespace command {

class ExitCommand : public BaseCommand {
 public:
  ExitCommand();

  Value Execute(std::map<std::string, Value>& storage) override;
};

}  // namespace command
