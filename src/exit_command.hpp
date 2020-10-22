#pragma once

#include "command.hpp"

namespace command {

class ExitCommand : public BaseCommand {
 public:
  ExitCommand();

  std::string Execute(std::map<std::string, std::string>& storage) override;
};

}  // namespace command
