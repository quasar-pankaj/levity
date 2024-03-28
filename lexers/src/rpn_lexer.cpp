#include "rpn_lexer.hpp"

namespace lexers {

std::vector<common::Token*> RpnLexer::tokenize() {
  while (current_ != source_.end()) {
    switch (*current_) {
      case ' ':
      case '\t':
      case '\n':
        skipWhitespace();
        break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case '.':
        parseNumber();
        break;
      case '"':
        parseString();
        break;
      default:
        parseIdentifier();
        break;
    }
  }

  return tokens_;
}

}  // namespace lexers