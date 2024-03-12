#pragma once

#include "number.hpp"
#include "object.hpp"
#include "operation_unsupported.hpp"
#include "string.hpp"

namespace common {

template <typename LHS, typename RHS>
Object *performOperation(const Object *lhs, const Object *rhs,
                         Object *(*op)(const LHS &, const RHS &)) {
  Number<LHS> *l = dynamic_cast<Number<LHS> *>(lhs);

  if (!l) {
    return nullptr;
  }

  Number<RHS> *r = dynamic_cast<Number<RHS> *>(rhs);

  if (!r) {
    return nullptr;
  }

  return op(l->getValue(), r->getValue());
}

template <typename LHS>
Object *performOperation<LHS, std::string>(const Object *lhs, const Object *rhs,
                                           Object *(*op)(const LHS &,
                                                         const std::string &)) {
  Number<LHS> *l = dynamic_cast<Number<LHS> *>(lhs);

  if (!l) {
    return nullptr;
  }

  String *r = dynamic_cast<String> * > (rhs);

  if (!r) {
    return nullptr;
  }

  return op(l->getValue(), r->getValue());
}

template <typename RHS>
Object *performOperation<std::string, RHS>(const Object *lhs, const Object *rhs,
                                           Object *(*op)(const std::string &,
                                                         const RHS &)) {
  String *l = dynamic_cast<String *>(lhs);

  if (!l) {
    return nullptr;
  }

  Number<RHS> *r = dynamic_cast<Number<RHS> *>(rhs);

  if (!r) {
    return nullptr;
  }

  return op(l->getValue(), r->getValue());
}

template <>
Object *performOperation<std::string, std::string>(
    const Object *lhs, const Object *rhs,
    Object *(*op)(const std::string &, const std::string &)) {
  String *l = dynamic_cast<String *>(const_cast<Object *>(lhs));

  if (!l) {
    return nullptr;
  }

  String *r = dynamic_cast<String *>(const_cast<Object *>(rhs));

  if (!r) {
    return nullptr;
  }

  return op(l->getValue(), r->getValue());
}

// Add variants
template <typename LHS, typename RHS>
Object *add(const LHS &lhs, const RHS &rhs) {
  return new Number<std::common_type_t<LHS, RHS>>(lhs + rhs);
}

template <typename RHS>
Object *add<std::string, RHS>(const std::string &lhs, const RHS &rhs) {
  return new String(lhs + rhs);
}

template <typename LHS>
Object *add<LHS, std::string>(const LHS &lhs, const std::string &rhs) {
  return new String(lhs + rhs);
}

template <>
Object *add<std::string, std::string>(const std::string &lhs,
                                      const std::string &rhs) {
  return new String(lhs + rhs);
}
// Add variants

// Sub variants
template <typename LHS, typename RHS>
Object *sub(const LHS &lhs, const RHS &rhs) {
  return new Number<std::common_type_t<LHS, RHS>>(lhs - rhs);
}

template <typename RHS,
          typename = std::enable_if_t<std::is_integral<RHS>::value>>
Object *sub<std::string, RHS>(const std::string &lhs, const RHS &rhs) {
  return new String(lhs.substr(0, lhs.size() - rhs.size()));
}

template <>
Object *sub<std::string, double>(const std::string &lhs, const double &rhs) {
  throw OperationUnsupported();
}

template <typename LHS,
          typename = std::enable_if_t<std::is_arithmetic<LHS>::value>>
Object *sub<double, std::string>(const LHS &lhs, const std::string &rhs) {
  throw OperationUnsupported();
}

template <typename LHS>
Object *sub<LHS, std::string>(const LHS &lhs, const std::string &rhs) {
  throw OperationUnsupported();
}
// Sub variants

// Mul variants
template <typename LHS, typename RHS>
Object *mul(const LHS &lhs, const RHS &rhs) {
  return new Number<std::common_type_t<LHS, RHS>>(lhs * rhs);
}

template <typename RHS,
          typename = std::enable_if_t<std::is_integral<RHS>::value>>
Object *mul<std::string, RHS>(const std::string &lhs, const RHS &rhs) {
  std::string result = "";
  for (size_t i = 0; i < rhs; i++) {
    result += lhs;
  }

  return new String(result);
}

template <>
Object *mul<std::string, double>(const std::string &lhs, const double &rhs) {
  throw OperationUnsupported();
}

template <typename LHS>
Object *mul<LHS, std::string>(const LHS &rhs, const std::string &lhs) {
  throw OperationUnsupported();
}
// Mul variants

// Div variants
template <typename LHS, typename RHS>
Object *div(const LHS &lhs, const RHS &rhs) {
  return new Number<std::common_type<LHS, RHS>::type>(lhs / rhs);
}

template <typename RHS>
Object *div<std::string, RHS>(const std::string &lhs, const RHS &rhs) {
  throw OperationUnsupported();
}

template <typename LHS>
Object *div<LHS, std::string>(const LHS &lhs, const std::string &rhs) {
  throw OperationUnsupported();
}
// Div variants

// Mod variants
template <typename LHS, typename RHS,
          typename = std::enable_if_t<std::is_integral<LHS>::value &&
                                      std::is_integral<RHS>::value>>
Object *mod(const LHS &lhs, const RHS &rhs) {
  return new Number<std::common_type<LHS, RHS>::type>(lhs % rhs);
}

template <typename LHS, typename RHS>
Object *mod(const LHS &lhs, const RHS &rhs) {
  throw OperationUnsupported();
}
// Mod variants

}  // namespace common
