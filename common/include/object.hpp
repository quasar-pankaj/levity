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

  virtual Object* add(const Object* rhs) = 0;
  virtual Object* subtract(const Object* rhs) = 0;
  virtual Object* multiply(const Object* rhs) = 0;
  virtual Object* divide(const Object* rhs) = 0;
  virtual Object* modulus(const Object* rhs) = 0;

 protected:
  void setType(ObjectType type) { type_ = type; }

 private:
  ObjectType type_;
};

}  // namespace common
