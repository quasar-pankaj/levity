#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "instruction.hpp"
#include "vm.hpp"

namespace common {

class Object : public Instruction {
 public:
  virtual ~Object() = default;

  virtual void execute(VM& vm){
    vm.push(this);
  }
};

}  // namespace common
