#include <iostream>
#include <string>
#include <vector>

namespace utils {
std::vector<std::string> SplitString(const std::string_view& data) {
  std::vector<std::string> result;

  std::string word;
  for (size_t i = 0; i < data.size(); ++i) {
    if (data[i] != ' ') {
      word.push_back(data[i]);
    } else if (!word.empty()) {
      result.push_back(std::move(word));
      word.clear();
    }
  }
  if (!word.empty()) {
    result.push_back(word);
  }

  return result;
}

std::string ContatinateStrings(const std::vector<std::string>& strings,
                               const std::string& separator) {
  std::string result;
  for (const auto& string : strings) {
    result += separator + string;
  }
  return result;
}

std::vector<std::string> SplitCommandString(const std::string_view& data) {
  std::vector<std::string> result;

  std::string word;
  int bracket_depth = 0;
  for (size_t i = 0; i < data.size(); ++i) {
    if (data[i] == '(') {
      ++bracket_depth;
      if (bracket_depth == 1) continue;
    }
    if (data[i] == ')') {
      --bracket_depth;
      if (bracket_depth == 0) continue;
    }
    if (data[i] != ' ' || bracket_depth) {
      word.push_back(data[i]);
    } else if (!word.empty()) {
      result.push_back(std::move(word));
      word.clear();
    }
  }
  if (!word.empty()) {
    result.push_back(word);
  }

  return result;
}

}  // namespace utils
