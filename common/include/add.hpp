#pragma once

#include "binary_operator.hpp"
#include "object.hpp"

namespace common {
class Add : public BinaryOperator {
 protected:
  Object* operate(Object* lhs, Object* rhs) override{
    return lhs->add(rhs);
  }
};
}  // namespace common