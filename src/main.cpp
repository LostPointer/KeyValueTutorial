#include <array>
#include <commands/command.hpp>
#include <iostream>
#include <unordered_map>

#include "utils.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
  std::map<std::string, std::string> storage;

  while (true) {
    try {
      std::string buffer;
      std::getline(std::cin, buffer);

      auto executed_command = command::MakeCommand(buffer);
      auto result = executed_command->Execute(storage);
      std::cout << result << std::endl;
    } catch (const std::exception& e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }
  return 0;
}
