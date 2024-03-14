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

  virtual std::string toString() const { return std::to_string(holder.value_); }

  Object* operator+(const Object* rhs) override;
  Object* operator-(const Object* rhs) override;
  Object* operator*(const Object* rhs) override;
  Object* operator/(const Object* rhs) override;
  Object* operator%(const Object* rhs) override;

  T getValue() const { return holder.value_; }
  void setValue(T value) { holder.value_ = value; }

 private:
  union typed_object {
    T value_;
    char bytes_[sizeof(T)];  // this is to handle endianness
  } holder;

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