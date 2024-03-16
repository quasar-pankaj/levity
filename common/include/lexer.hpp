#pragma once

#include <string>
#include <vector>

namespace common {
class Lexer {
 public:
  explicit Lexer(const std::string& source);
  std::vector<std::string> tokenize();
  std::vector<std::string> tokenize(const std::string& source);
  std::vector<std::string> tokenize(const std::string& source,
                                    const std::string& delimiters);

 private:
  std::string source_;
  std::string::const_iterator current_;
  std::vector<std::string> tokens_;
};
}  // namespace common