#pragma once

#include "instruction.hpp"
#include "object.hpp"

namespace common {

class TernaryOperator : public Instruction {
 public:
  virtual void execute(VM& vm) = 0;

 protected:
  virtual Object* operate(Object* arg1, Object* arg2, Object* arg3) = 0;
};

} 