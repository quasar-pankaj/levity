#pragma once

#include <cstdint>
#include <stack>
#include <string>
#include <type_traits>
#include <vector>

#include "instruction.hpp"
#include "object.hpp"

namespace common {

class VM {
 public:
  VM() = default;
  virtual ~VM() = default;

  void run();

  void push(Object* object) { ds.push(object); }
  Object* pop() {
    Object* object = ds.top();
    ds.pop();
    return object;
  }

 protected:
  std::vector<Instruction*> instructions;
  std::stack<Object*> ds;                  // Data stack
  std::stack<int> rs;                      // Return stack
  std::vector<Instruction*>::iterator ip;  // Instruction pointer
};

}  // namespace common
