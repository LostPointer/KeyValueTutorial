#pragma once

#include "command.hpp"

namespace command {

class GetCommand : public BaseCommand {
 public:
  GetCommand(const std::vector<std::string>& args);

  std::string Execute(std::map<std::string, std::string>& storage) final;

 private:
  std::string key;
};
}  // namespace command
