#pragma once

#include "binary_operator.hpp"
#include "object.hpp"

namespace common {
class Multiply : public BinaryOperator {
 protected:
  Object* operate(Object* lhs, Object* rhs) override {
    return lhs->multiply(rhs);
  }
};
}  // namespace common