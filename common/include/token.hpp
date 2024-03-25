#pragma once

#include <string>

namespace common {
class Token {
 public:
  enum class Type {
    Float,
    Integer,
    String,
    Add,
    Subtract,
    Multiply,
    Divide,
    Modulus,
    Equals,
    Halt,
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