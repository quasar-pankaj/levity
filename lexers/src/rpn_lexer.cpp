#include "rpn_lexer.hpp"

#include <stdexcept>
// #include <sstream>

namespace lexers {

std::vector<common::Token*> RpnLexer::tokenize() {
  // std::stringstream ss(source_);
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
    if (std::isalpha(static_cast<unsigned char>(*current_))) {
      parseIdentifier();
      continue;
    }
    switch (*current_) {
      case '+':
      case '-':
      case '*':
      case '/':
      case '%':
      {
        unsigned char ch = static_cast<unsigned char>(*current_);
        std::string value(1, ch);
        tokens_.push_back(
            new common::Token(common::Token::Type::Operator, value));
        ++current_;
        break;
      }
      // Add more cases here to handle keywords
      default:
        throw std::runtime_error("Unexpected character: " +
                                 std::string(1, *current_));
    }
  }

  return tokens_;
}

}  // namespace lexers