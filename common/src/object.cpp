#include "object.hpp"

#include "object_operators.hpp"

namespace common {
Object* Object::operator+(const Object* rhs) {
  Object* result = performOperation<double, double>(this, rhs, add);
  if (result) {
    return result;
  }
  result = performOperation<double, long>(this, rhs, add);
  if (result) {
    return result;
  }
  result = performOperation<long, double>(this, rhs, add);
  if (result) {
    return result;
  }
  result = performOperation<long, long>(this, rhs, add);
  if (result) {
    return result;
  }
  result = performOperation<std::string, double>(this, rhs, add);
  if (result) {
    return result;
  }
  result = performOperation<std::string, long>(this, rhs, add);
  if (result) {
    return result;
  }
  result = performOperation<double, std::string>(this, rhs, add);
  if (result) {
    return result;
  }
  result = performOperation<long, std::string>(this, rhs, add);
  if (result) {
    return result;
  }
  result = performOperation<std::string, std::string>(this, rhs, add);
  if (result) {
    return result;
  }

  throw OperationUnsupported();
}
}  // namespace common
