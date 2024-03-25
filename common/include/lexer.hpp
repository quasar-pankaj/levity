#pragma once

#include <string>
#include <vector>

#include "token.hpp"

namespace common {
class Lexer {
 public:
  explicit Lexer(const std::string& source)
      : source_(source), current_(source_.begin()) {}
  std::vector<Token*>
  tokenize();  // Make sure to return tokens in the correct postfix order

 private:
  std::string source_;
  std::string::const_iterator current_;
  std::vector<Token*> tokens_;

  void skipWhitespace();
  void parseNumber();
  void parseString();
  void parseIdentifier();
};
}  // namespace common