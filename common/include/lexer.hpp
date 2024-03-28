#pragma once

#include <string>
#include <vector>

#include "token.hpp"

namespace common {
class Lexer {
 public:
  explicit Lexer(const std::string& filename);
  virtual ~Lexer();

  // Make sure to return tokens in the correct postfix order
  virtual std::vector<Token*> tokenize() = 0;

 protected:
  std::string source_;
  std::string::iterator current_;
  std::vector<Token*> tokens_;

  void parseIdentifier();
  void parseNumber();
  void parseString();
  void skipWhitespace();
};
}  // namespace common