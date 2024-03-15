#include "typed_object.hpp"

#include <cmath>

#include "operation_unsupported.hpp"

namespace common {

template <typename T>
TypedObject<T>::TypedObject(T value) : holder{value} {
  if (typeid(T) == typeid(double) || typeid(T) == typeid(long)) {
    setType(ObjectType::Number);
  } else if (typeid(T) == typeid(std::string)) {
    setType(ObjectType::String);
  } else if (typeid(T) == typeid(bool)) {
    setType(ObjectType::Logical);
  } else if (typeid(T) == typeid(std::vector<Object*>)) {
    setType(ObjectType::List);
  } else {
    setType(ObjectType::Object);
  }
}

template <typename T>
template <typename RHS>
Object* TypedObject<T>::add(const T& lhs, const RHS& rhs) {
  throw OperationUnsupported();
}
template <typename T>
template <typename RHS>
Object* TypedObject<T>::sub(const T& lhs, const RHS& rhs) {
  throw OperationUnsupported();
}
template <typename T>
template <typename RHS>
Object* TypedObject<T>::mul(const T& lhs, const RHS& rhs) {
  throw OperationUnsupported();
}
template <typename T>
template <typename RHS>
Object* TypedObject<T>::div(const T& lhs, const RHS& rhs) {
  throw OperationUnsupported();
}
template <typename T>
template <typename RHS>
Object* TypedObject<T>::mod(const T& lhs, const RHS& rhs) {
  throw OperationUnsupported();
}

/**
 * Template specializations for common types
 */
/// ---------Add Specializations for double------------
template <>
template <>
Object* TypedObject<double>::add<double>(const double& lhs, const double& rhs) {
  return new TypedObject<double>(lhs + rhs);
}
template <>
template <>
Object* TypedObject<double>::add<long>(const double& lhs, const long& rhs) {
  return new TypedObject<double>(lhs + rhs);
}
template <>
template <>
Object* TypedObject<double>::add<std::string>(const double& lhs,
                                              const std::string& rhs) {
  return new TypedObject<std::string>(std::to_string(lhs) + rhs);
}

/// ----------Sub Specializations for double-----------
template <>
template <>
Object* TypedObject<double>::sub<double>(const double& lhs, const double& rhs) {
  return new TypedObject<double>(lhs - rhs);
}
template <>
template <>
Object* TypedObject<double>::sub<long>(const double& lhs, const long& rhs) {
  return new TypedObject<double>(lhs - rhs);
}

/// ---------Mul Specializations for double----------
template <>
template <>
Object* TypedObject<double>::mul<double>(const double& lhs, const double& rhs) {
  return new TypedObject<double>(lhs * rhs);
}
template <>
template <>
Object* TypedObject<double>::mul<long>(const double& lhs, const long& rhs) {
  return new TypedObject<double>(lhs * rhs);
}

/// ---------Div Specializations for double----------
template <>
template <>
Object* TypedObject<double>::div<double>(const double& lhs, const double& rhs) {
  return new TypedObject<double>(lhs / rhs);
}
template <>
template <>
Object* TypedObject<double>::div<long>(const double& lhs, const long& rhs) {
  return new TypedObject<double>(lhs / rhs);
}

/// ------------Mod Specializations for double-----------
template <>
template <>
Object* TypedObject<double>::mod<double>(const double& lhs, const double& rhs) {
  return new TypedObject<double>(fmod(lhs, rhs));
}
template <>
template <>
Object* TypedObject<double>::mod<long>(const double& lhs, const long& rhs) {
  return new TypedObject<double>(fmod(lhs, rhs));
}

/// ------------Add Specializations for long----------
template <>
template <>
Object* TypedObject<long>::add<long>(const long& lhs, const long& rhs) {
  return new TypedObject<long>(lhs + rhs);
}
template <>
template <>
Object* TypedObject<long>::add<double>(const long& lhs, const double& rhs) {
  return new TypedObject<double>(lhs + rhs);
}
template <>
template <>
Object* TypedObject<long>::add<std::string>(const long& lhs,
                                            const std::string& rhs) {
  return new TypedObject<std::string>(std::to_string(lhs) + rhs);
}

/// -------------Sub Specializations for long----------
template <>
template <>
Object* TypedObject<long>::sub<long>(const long& lhs, const long& rhs) {
  return new TypedObject<long>(lhs - rhs);
}
template <>
template <>
Object* TypedObject<long>::sub<double>(const long& lhs, const double& rhs) {
  return new TypedObject<double>(lhs - rhs);
}

/// -----------Mul Specializations for long-----------
template <>
template <>
Object* TypedObject<long>::mul<long>(const long& lhs, const long& rhs) {
  return new TypedObject<long>(lhs * rhs);
}
template <>
template <>
Object* TypedObject<long>::mul<double>(const long& lhs, const double& rhs) {
  return new TypedObject<double>(lhs * rhs);
}

/// ------------Div Specializations for long---------
template <>
template <>
Object* TypedObject<long>::div<long>(const long& lhs, const long& rhs) {
  return new TypedObject<double>(lhs / rhs);
}
template <>
template <>
Object* TypedObject<long>::div<double>(const long& lhs, const double& rhs) {
  return new TypedObject<double>(lhs / rhs);
}

/// ----------Mod Specializations for long---------
template <>
template <>
Object* TypedObject<long>::mod<double>(const long& lhs, const double& rhs) {
  return new TypedObject<double>(fmod(lhs, rhs));
}
template <>
template <>
Object* TypedObject<long>::mod<long>(const long& lhs, const long& rhs) {
  return new TypedObject<long>(lhs % rhs);
}

/// ----------Add Specializations for std::string----------
template <>
template <>
Object* TypedObject<std::string>::add<std::string>(const std::string& lhs,
                                                   const std::string& rhs) {
  return new TypedObject<std::string>(lhs + rhs);
}
template <>
template <>
Object* TypedObject<std::string>::add<long>(const std::string& lhs,
                                            const long& rhs) {
  return new TypedObject<std::string>(lhs + std::to_string(rhs));
}
template <>
template <>
Object* TypedObject<std::string>::add<double>(const std::string& lhs,
                                              const double& rhs) {
  return new TypedObject<std::string>(lhs + std::to_string(rhs));
}
template <>
template <>
Object* TypedObject<std::string>::add<bool>(const std::string& lhs,
                                            const bool& rhs) {
  return new TypedObject<std::string>(lhs + (rhs ? "true" : "false"));
}

/// ----------Sub Specializations for std::string----------
template <>
template <>
Object* TypedObject<std::string>::sub<long>(const std::string& lhs,
                                            const long& rhs) {
  return new TypedObject<std::string>(lhs.substr(0, lhs.size() - rhs));
}
template <>
template <>
Object* TypedObject<std::string>::sub<std::string>(const std::string& lhs,
                                                   const std::string& rhs) {
  size_t pos = lhs.find(rhs);
  if (pos != std::string::npos) {
    return new TypedObject<std::string>(lhs.substr(0, pos) +
                                        lhs.substr(pos + rhs.size()));
  }
  return new TypedObject<std::string>(lhs);
}

/// ----------Mul Specializations for std::string----------
template <>
template <>
Object* TypedObject<std::string>::mul<long>(const std::string& lhs,
                                            const long& rhs) {
  std::string result;
  for (long i = 0; i < rhs; i++) {
    result += lhs;
  }
  return new TypedObject<std::string>(result);
}

/**
 * Perform operation on two typed objects
 * @tparam T
 * @tparam RHS
 * @param lhs
 * @param rhs
 * @return a typed object
 */
template <typename T>
template <typename RHS>
Object* TypedObject<T>::performOperation(const Object* rhs,
                                         Object* (*op)(const T&, const RHS&)) {
  TypedObject<RHS>* r = dynamic_cast<TypedObject<RHS>*>(rhs);
  if (!r) {
    return nullptr;
  }
  return op(holder.value_, r->holder.value_);
}

template <typename T>
Object* TypedObject<T>::add(const Object* rhs) {
  Object* result;
  result = performOperation<double>(rhs, add<double>);
  if (result) return result;
  result = performOperation<long>(rhs, add<long>);
  if (result) return result;
  result = performOperation<std::string>(rhs, add<std::string>);
  if (result) return result;
  result = performOperation<bool>(rhs, add<bool>);
  if (result) return result;
  return performOperation(rhs, add<T>);
}
template <typename T>
Object* TypedObject<T>::subtract(const Object* rhs) {
  Object* result;
  result = performOperation<double>(rhs, sub<double>);
  if (result) return result;
  result = performOperation<long>(rhs, sub<long>);
  if (result) return result;
  result = performOperation<std::string>(rhs, sub<std::string>);
  if (result) return result;
  result = performOperation<bool>(rhs, sub<bool>);
  if (result) return result;
  return performOperation(rhs, sub<T>);
}
template <typename T>
Object* TypedObject<T>::multiply(const Object* rhs) {
  Object* result;
  result = performOperation<double>(rhs, mul<double>);
  if (result) return result;
  result = performOperation<long>(rhs, mul<long>);
  if (result) return result;
  result = performOperation<std::string>(rhs, mul<std::string>);
  if (result) return result;
  result = performOperation<bool>(rhs, mul<bool>);
  if (result) return result;
  return performOperation(rhs, mul<T>);
}
template <typename T>
Object* TypedObject<T>::divide(const Object* rhs) {
  Object* result;
  result = performOperation<double>(rhs, div<double>);
  if (result) return result;
  result = performOperation<long>(rhs, div<long>);
  if (result) return result;
  result = performOperation<std::string>(rhs, div<std::string>);
  if (result) return result;
  result = performOperation<bool>(rhs, div<bool>);
  if (result) return result;
  return performOperation(rhs, div<T>);
}
template <typename T>
Object* TypedObject<T>::modulus(const Object* rhs) {
  Object* result;
  result = performOperation<double>(rhs, mod<double>);
  if (result) return result;
  result = performOperation<long>(rhs, mod<long>);
  if (result) return result;
  result = performOperation<std::string>(rhs, mod<std::string>);
  if (result) return result;
  result = performOperation<bool>(rhs, mod<bool>);
  if (result) return result;
  return performOperation(rhs, mod<T>);
}

}  // namespace common