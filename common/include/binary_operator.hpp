#pragma once

#include "instruction.hpp"
#include "object.hpp"

namespace common {

class BinaryOperator : public Instruction {
 public:
  virtual void execute(VM& vm) = 0;

 protected:
  virtual Object* operate(Object* lhs, Object* rhs) = 0;
};

}  // namespace common