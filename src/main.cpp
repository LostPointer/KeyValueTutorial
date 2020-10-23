#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using Storage = std::map<std::string, std::string>;

std::vector<std::string> SplitString(const std::string& line) {
  std::stringstream stream(line);
  std::vector<std::string> result;
  while (stream) {
    std::string part;
    stream >> part;
    result.push_back(part);
  }

  return result;
}

struct Command {
  std::string command;
  std::vector<std::string> args;
  Command(const std::string& command_string) {
    auto splited_command = SplitString(command_string);

    command = splited_command.at(0);

    args.insert(args.begin(), splited_command.begin() + 1,
                splited_command.end());
  }
};

int main() {
  std::map<std::string, std::string> storage;

  while (true) {
    std::string buffer;
    std::getline(std::cin, buffer);

    const auto& command = Command(buffer);

    if (command.command == "Exit") {
      std::cout << "Exit!" << std::endl;
      exit(0);
    } else if (command.command == "Put") {
      storage[command.args.at(0)] = command.args.at(1);
      std::cout << "Put [" << command.args[0] << "] = " << command.args[1]
                << "\n";
    } else if (command.command == "Get") {
      std::cout << command.args.at(0) << ": " << storage[command.args.at(0)];
    } else if (command.command == "help") {
      std::cout
          << "Available commands:\n Exit - [Exit] exit from program\nPut - "
             "[Put (key) (value)]. Put in storage in key value\nGet - [Get "
             "(value)]. Get value by (key)";
    }
  }
}
