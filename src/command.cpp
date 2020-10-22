#include "command.hpp"

#include <iostream>
#include <sstream>

#include "exit_command.hpp"
#include "get_command.hpp"
#include "put_command.hpp"
#include "utils.hpp"

namespace command {

std::unique_ptr<BaseCommand> MakeCommand(const std::string& command_string) {
  auto splitted_command = utils::SplitString(command_string, " ");
  std::stringstream debug;
  debug << "debug begin\n";
  for (const auto& i : splitted_command) {
    debug << i << "\n";
  }
  debug << "end debug\n";
  std::cout << debug.str() << "\n";
  std::vector<std::string> args;
  std::cout << "fofofofoof\n";
  args.insert(args.end(), splitted_command.begin(), splitted_command.end());

  std::cout << "akjdjklasjdlajdl" << std::endl;

  std::stringstream debug_args;
  debug_args << "debug args begin\n" << args.size() << "\n";
  for (const auto& i : args) {
    std::cout << "foo " << i << std::endl;
    debug << i << " h\n";
  }
  std::cout << "exit from range-based for" << std::endl;
  debug << "end debug args\n";
  std::cout << debug_args.str() << "\n";

  if (splitted_command.size() < 1) {
    throw BadCommand("Command need have name");
  }

  std::cout << "splitted_command.size() = " << splitted_command.size()
            << std::endl;
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
