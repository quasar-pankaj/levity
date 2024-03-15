#pragma once

#include "instruction.hpp"
#include "vm.hpp"

namespace common {
class Halt : public Instruction {
 public:
  void execute(VM& vm) override { vm.halt(); }
};
}  // namespace common