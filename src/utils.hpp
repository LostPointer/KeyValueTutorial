#pragma once

#include <string>
#include <vector>

namespace utils {
std::vector<std::string> SplitString(const std::string_view& data,
                                     const std::string_view& separator);

std::string ContatinateStrings(const std::vector<std::string>& strings,
                               const std::string& separator);
}  // namespace utils
