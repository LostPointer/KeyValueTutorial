#pragma once

#include <string>

class Value {
 public:
  Value(const std::string& value);
  Value();

  std::string ToString() const;

 private:
  std::string value_;
};
