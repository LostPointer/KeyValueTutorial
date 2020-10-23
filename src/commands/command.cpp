#include "command.hpp"

#include <commands/exit_command.hpp>
#include <commands/get_command.hpp>
#include <commands/put_command.hpp>
#include <iostream>
#include <sstream>

#include "utils.hpp"

namespace command {

std::unique_ptr<BaseCommand> MakeCommand(const std::string& command_string) {
  auto splitted_command = utils::SplitString(command_string, " ");

  if (splitted_command.size() < 1) {
    throw BadCommand("Command need have name");
  }

  if (splitted_command[0] == "put" || splitted_command[0] == "p") {
    std::vector<std::string> args;
    args.insert(args.begin(), splitted_command.begin() + 1,
                splitted_command.end());
    return std::make_unique<PutCommand>(args);
  }

  if (splitted_command[0] == "get" || splitted_command[0] == "g") {
    std::vector<std::string> args;
    args.insert(args.begin(), splitted_command.begin() + 1,
                splitted_command.end());
    return std::make_unique<GetCommand>(args);
  }

  if (splitted_command[0] == "exit" || splitted_command[0] == "e") {
    return std::make_unique<ExitCommand>();
  }

  throw UnknownCommand("Unknown command for string" + command_string);
}

}  // namespace command