#include "value.hpp"

Value::Value(const std::string &value) : value_(value) {}

Value::Value() : value_{} {}

std::string Value::ToString() const { return value_; }
