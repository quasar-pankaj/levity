#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "instruction.hpp"
#include "vm.hpp"

namespace common {

enum class ObjectType { Number, String, Logical, List, Object };

class Object : public Instruction {
 public:
  Object() = default;
  virtual ~Object() = default;

  virtual void execute(VM& vm) { vm.push(this); }

  virtual std::string toString() const = 0;

  ObjectType getType() const { return type_; }

  virtual Object* operator+(const Object* rhs) = 0;
  virtual Object* operator-(const Object* rhs) = 0;
  virtual Object* operator*(const Object* rhs) = 0;
  virtual Object* operator/(const Object* rhs) = 0;
  virtual Object* operator%(const Object* rhs) = 0;

 protected:
  void setType(ObjectType type) { type_ = type; }

 private:
  ObjectType type_;
};

}  // namespace common
