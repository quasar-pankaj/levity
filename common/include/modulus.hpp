#pragma once

#include "binary_operator.hpp"
#include "object.hpp"

namespace common {
class Modulus : public BinaryOperator {
 protected:
  Object* operate(Object* lhs, Object* rhs) override {
    return lhs->modulus(rhs);
  }
};
}  // namespace common