#pragma once

#include "binary_operator.hpp"
#include "object.hpp"

namespace common {
class Subtract : public BinaryOperator {
 protected:
  Object* operate(Object* lhs, Object* rhs) override{
    return lhs->subtract(rhs);
  }
};
}  // namespace common