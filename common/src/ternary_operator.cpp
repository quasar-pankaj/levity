#include "ternary_operator.hpp"

namespace common {
void TernaryOperator::execute(VM& vm) {
  Object* arg3 = vm.pop();
  Object* arg2 = vm.pop();
  Object* arg1 = vm.pop();
  Object* result = operate(arg1, arg2, arg3);
  if (result) vm.push(result);
}
}  // namespace common