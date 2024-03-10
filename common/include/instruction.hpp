#pragma once

namespace common {

class VM;

class Instruction {
 public:
  virtual void execute(VM& vm) = 0;
};

}  // namespace common
