#pragma once

#include "unary_operator.hpp"

namespace common {

class Print : public UnaryOperator {
 protected:
  Object* operate(Object* argument) override;
};

}  // namespace common