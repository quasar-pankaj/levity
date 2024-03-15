#pragma once

#include "binary_operator.hpp"
#include "object.hpp"

namespace common {
class Divide : public BinaryOperator {
 protected:
  Object* operate(Object* lhs, Object* rhs) override {
    return lhs->divide(rhs);
  }
};
}  // namespace common