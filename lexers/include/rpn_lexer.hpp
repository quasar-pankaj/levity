#pragma once

#include "lexer.hpp"

namespace lexers {

class RpnLexer : public common::Lexer {
 public:
  RpnLexer(const std::string& filename) : common::Lexer(filename) {}
  virtual ~RpnLexer() {}

  std::vector<common::Token*> tokenize() override;
};
}  // namespace lexers