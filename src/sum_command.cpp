#include "sum_command.hpp"

namespace command {

SumCommand::SumCommand(const std::vector<Arg>& args) : BaseCommand(args) {}

Value SumCommand::Execute(std::map<std::string, Value>& storage) {
  std::string result;
  for (const auto& arg : args_) {
    result += arg.Get(storage).ToString();
  }
  return result;
}

}  // namespace command
