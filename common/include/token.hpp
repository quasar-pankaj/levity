#pragma once

#include <string>

namespace common {
class Token {
 public:
  enum class Type {
    Number,
    String,
    Logical,
    List,
    Object,
    Instruction,
    Halt
  };
  
  Token(Type type, const std::string& value) : type_(type), value_(value) {}
  virtual ~Token() = default;
  Type getType() const{ return type_; }
  std::string getValue() const { return value_; }

  private:
    Type type_;
    std::string value_;
};
}  // namespace common