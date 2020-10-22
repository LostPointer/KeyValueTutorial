#pragma once

#include "command.hpp"

namespace command {

class PutCommand : public BaseCommand {
 public:
  PutCommand(const std::vector<std::string>& args);

  std::string Execute(std::map<std::string, std::string>& storage) override;

 private:
  std::string key;
  std::string value;
};
}  // namespace command
