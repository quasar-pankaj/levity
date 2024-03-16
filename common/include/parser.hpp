#pragma once

#include <string>
#include <vector>

#include "lexer.hpp"
#include "instruction.hpp"

namespace common {
class Parser {
 public:
  virtual std::vector<Instruction*> parse(const Lexer *lexer) = 0;
};
}  // namespace common