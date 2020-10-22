#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace utils {
std::vector<std::string> SplitString(const std::string_view& data,
                                     const std::string_view& separator) {
  if (data.empty()) return {};

  size_t first_separator = data.find(separator);
  if (first_separator == data.npos) return {std::string{data}};

  std::string first_part = std::string{data.substr(0, first_separator)};
  auto last_part =
      SplitString(data.substr(first_separator + separator.size()), separator);
  std::vector<std::string> result{first_part};
  result.insert(result.end(), last_part.begin(), last_part.end());

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

}  // namespace utils
