#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "instruction.hpp"
#include "vm.hpp"

namespace common {

enum class ObjectType { Number, String, Logical };

class Object : public Instruction {
 public:
  Object() = default;

  virtual ~Object() = default;

  virtual void execute(VM& vm) { vm.push(this); }

  virtual std::string toString() const = 0;

  virtual ObjectType getType() const = 0;

  Object* operator+(const Object* rhs);
  Object* operator-(const Object* rhs);
  Object* operator*(const Object* rhs);
  Object* operator/(const Object* rhs);
  Object* operator%(const Object* rhs);
};

}  // namespace common
