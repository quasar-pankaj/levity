#include "rpn_lexer.hpp"

#include <stdexcept>

namespace lexers {

std::vector<common::Token*> RpnLexer::tokenize() {
  while (current_ != source_.end()) {
    if (std::isspace(static_cast<unsigned char>(*current_))) {
      skipWhitespace();
      continue;
    }
    if (std::isdigit(static_cast<unsigned char>(*current_)) ||
        *current_ == '.') {
      parseNumber();
      continue;
    }
    if (*current_ == '"') {
      parseString();
      continue;
    }
    if (*current_ == '+' || *current_ == '-' || *current_ == '*' ||
        *current_ == '/' || *current_ == '%') {
      unsigned char ch = static_cast<unsigned char>(*current_);
      std::string value(1, ch);
      tokens_.push_back(
          new common::Token(common::Token::Type::Operator, value));
      ++current_;
      continue;
    }
    if (std::isalpha(static_cast<unsigned char>(*current_))) {
      parseIdentifier();
      continue;
    }

    throw std::runtime_error("Unexpected character: " +
                             std::string(1, *current_));
  }

  return tokens_;
}

}  // namespace lexers