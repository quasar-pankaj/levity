#pragma once

#include <exception>
#include <stdexcept>

namespace common {
class OperationUnsupported : public std::exception {
 public:
  const char* what() const noexcept override { return "Unsupported operation"; }
};
}  // namespace common