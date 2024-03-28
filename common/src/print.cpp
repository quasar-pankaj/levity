#include "print.hpp"

#include <iostream>

namespace common {

Object* Print::operate(Object* argument) {
  std::cout << argument->toString() << std::endl;
}

}  // namespace common