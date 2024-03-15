#include "unary_operator.hpp"

namespace common {
void UnaryOperator::execute(VM& vm) {
  Object* arg = vm.pop();
  Object* result = operate(arg);
  if (result) vm.push(result);
}
}  // namespace common