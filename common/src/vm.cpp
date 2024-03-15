#include "vm.hpp"

namespace common {

void VM::run() {
  for (auto ip = instructions.begin(); ip != instructions.end() && isRunning; ip++) {
    (*ip)->execute(*this);
  }
}

}  // namespace common
