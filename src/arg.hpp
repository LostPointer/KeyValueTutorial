#pragma once

#include <map>
#include <string>
#include <vector>

#include "value.hpp"

class ValueError : public std::runtime_error {
 public:
  using std::runtime_error::runtime_error;
};

class BadConvert : public ValueError {
  using ValueError::ValueError;
};

class Arg {
 public:
  Arg(const std::string& arg);

  Value Get(std::map<std::string, Value>& storage) const;

  int ToInt() const;
  double ToDouble() const;

 private:
  std::string arg_;

  bool IsCommand() const;
};

template <class Iterator>
std::vector<Arg> MakeArgs(Iterator begin, Iterator end) {
  std::vector<Arg> result;
  while (begin != end) {
    result.emplace_back(*begin);
    ++begin;
  }
  return result;
}
