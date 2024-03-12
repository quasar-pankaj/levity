#pragma once

#include <cstring>
#include <string>
#include <type_traits>

#include "object.hpp"

namespace common {

// template<typename T, typename =
// std::enable_if_t<std::is_arithmetic<T>::value>> // use if you need all
// arithmetci types
template <typename T,
          typename = std::enable_if_t<std::is_same<T, long>::value ||
                                      std::is_same<T, double>::value>>
class Number : public Object {
 public:
  Number(T value) : Object(), holder{.value_ = value} {}
  Number(char *bytes) { std::memcpy(this->holder.bytes_, bytes, sizeof(T)); }

  virtual ~Number() = default;

  operator T() const { return holder.value_; }

  T getValue() const { return holder.value_; }
  void setValue(T value) { holder.value_ = value; }

  char *getBytes() const { return holder.bytes_; }
  size_t getBytesSize() const { return sizeof(T); }
  void toBytes(char *bytes) const {
    std::memcpy(bytes, holder.bytes_, sizeof(T));
  }
  void fromBytes(char *bytes) { std::memcpy(holder.bytes_, bytes, sizeof(T)); }

  std::string toString() const override {
    return std::to_string(holder.value_);
  }

  ObjectType getType() const override { return ObjectType::Number; }

  

 private:
  union number_holder {
    T value_;
    char bytes_[sizeof(T)];  // this is to handle endianness
  } holder;
};

}  // namespace common
