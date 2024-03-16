#include "vm.hpp"

namespace common {

VM::VM(std::string source, Loader *loader) {
  instructions = loader->load(source);
}

VM::~VM() {
  for (auto instruction : instructions) {
    delete instruction;
  }

  instructions.clear();

  while (!ds.empty()) {
    delete ds.top();
    ds.pop();
  }

  while (!rs.empty()) {
    rs.pop();
  }
}

void VM::run() {
  for (auto ip = instructions.begin(); ip != instructions.end() && isRunning;
       ip++) {
    (*ip)->execute(*this);
  }
}

}  // namespace common
