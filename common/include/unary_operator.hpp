#pragma once

#include "instruction.hpp"
#include "object.hpp"

namespace common {

class UnaryOperator : public Instruction {
 public:
  void execute(VM& vm) override;

 protected:
  virtual Object* operate(Object* argument) = 0;
};

}  // namespace common