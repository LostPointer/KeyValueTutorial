#include "sum_command.hpp"

namespace command {

SumCommand::SumCommand(const std::vector<Arg>& args) : BaseCommand(args) {}

Value SumCommand::Execute(std::map<std::string, Value>& storage) {
  try {
    int int_result = 0;
    for (const auto& arg : args_) {
      int_result += arg.ToInt();
    }
    return std::to_string(int_result);
  } catch (const BadConvert&) {
  }

  try {
    double double_result = 0;
    for (const auto& arg : args_) {
      double_result += arg.ToDouble();
    }
    return std::to_string(double_result);
  } catch (const BadConvert&) {
  }

  std::string result;
  for (const auto& arg : args_) {
    result += arg.Get(storage).ToString();
  }
  return result;
}

}  // namespace command
