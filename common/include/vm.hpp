#pragma once

#include <stack>
#include <string>
#include <vector>

#include "instruction.hpp"
#include "loader.hpp"
#include "object.hpp"

namespace common {

class VM {
 public:
  VM(std::string source, Loader* loader);
  virtual ~VM();

  void run();

  void push(Object* object) { ds.push(object); }
  Object* pop() {
    Object* object = ds.top();
    ds.pop();
    return object;
  }

  void halt() { isRunning = false; }

 protected:
  std::vector<Instruction*> instructions;
  std::stack<Object*> ds;                              // Data stack
  std::stack<std::vector<Instruction*>::iterator> rs;  // Return stack
  std::vector<Instruction*>::iterator ip;              // Instruction pointer
  bool isRunning = true;
};

}  // namespace common
