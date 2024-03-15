#include "binary_operator.hpp"

namespace common {
void BinaryOperator::execute(VM& vm) {
  Object* rhs = vm.pop();
  Object* lhs = vm.pop();
  Object* result = operate(lhs, rhs);
  if (result) vm.push(result);
}
}  // namespace common