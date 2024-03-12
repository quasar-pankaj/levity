#pragma once

#include <string>

#include "object.hpp"

namespace common {

class String : public Object {
 public:
  String() = default;
  String(const std::string& value) : Object(), value_{value} {}
  virtual ~String() = default;

  std::string getValue() const { return value_; }
  void setValue(const std::string& value) { value_ = value; }
  std::string toString() const override { return value_; }

  ObjectType getType() const override { return ObjectType::String; }

 private:
  std::string value_;
};

}  // namespace common