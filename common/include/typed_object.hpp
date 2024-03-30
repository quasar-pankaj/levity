#pragma once

#include <typeinfo>

#include "object.hpp"

namespace common {

template <typename T>
class TypedObject : public Object {
 public:
  TypedObject(T value);
  TypedObject() = default;
  virtual ~TypedObject() = default;

  virtual std::string toString() const { return std::to_string(value_); }

  Object* add(const Object* rhs) override;
  Object* subtract(const Object* rhs) override;
  Object* multiply(const Object* rhs) override;
  Object* divide(const Object* rhs) override;
  Object* modulus(const Object* rhs) override;

  T getValue() const { return value_; }
  void setValue(T value) { value_ = value; }

 private:
  T value_;

  template<typename RHS>
  Object* performOperation(const Object* rhs, Object *(*op)(const T&, const RHS&));

  template<typename RHS>
  Object* add(const T& lhs, const RHS& rhs);
  template<typename RHS>
  Object* sub(const T& lhs, const RHS& rhs);
  template<typename RHS>
  Object* mul(const T& lhs, const RHS& rhs);
  template<typename RHS>
  Object* div(const T& lhs, const RHS& rhs);
  template<typename RHS>
  Object* mod(const T& lhs, const RHS& rhs);
};

}  // namespace common