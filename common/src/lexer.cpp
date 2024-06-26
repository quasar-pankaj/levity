#include "lexer.hpp"

#include <cctype>
#include <fstream>
#include <stdexcept>

namespace common {

Lexer::Lexer(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file");
  }
  std::string source((std::istreambuf_iterator<char>(file)),
                     std::istreambuf_iterator<char>());
  source_ = source;
}

Lexer::~Lexer() {
  for (auto token : tokens_) {
    delete token;
  }
  tokens_.clear();
}

void Lexer::skipWhitespace() {
  while (std::isspace(static_cast<unsigned char>(*current_))) current_++;
}

void Lexer::parseNumber() {
  std::string value;
  bool isFloat = false;
  while (current_ != source_.end() &&
         std::isdigit(static_cast<unsigned char>(*current_))) {
    value += *current_;
    ++current_;
  }
  if (*current_ == '.') {
    isFloat = true;
    value += *current_;
    ++current_;
  }
  while (current_ != source_.end() &&
         std::isdigit(static_cast<unsigned char>(*current_))) {
    value += *current_;
    ++current_;
  }
  if (isFloat) {
    tokens_.push_back(new Token(Token::Type::Float, value));
  } else {
    tokens_.push_back(new Token(Token::Type::Integer, value));
  }
}

void Lexer::parseString() {
  std::string value;
  while (current_ != source_.end() && *current_ != '"') {
    value += *current_;
    ++current_;
  }
  if (*current_ != '"') {
    throw std::runtime_error("Unterminated string");
  }
  ++current_;
  tokens_.push_back(new Token(Token::Type::String, value));
}

void Lexer::parseIdentifier() {
  std::string value;
  while (current_ != source_.end() &&
         std::isalnum(static_cast<unsigned char>(*current_))) {
    value += *current_;
    ++current_;
  }
  tokens_.push_back(new Token(Token::Type::Identifier, value));
}

bool Lexer::peek(const char c) {
  return (*current_ == c);
}

bool Lexer::consume(const char c) {
  if (*current_ == c) {
    ++current_;
    return true;
  }
  return false;
}

bool Lexer::consume(const char* str) {
  std::string::iterator start = current_;
  for (const char* c = str; *c != '\0' && current_ != source_.end(); ++c) {
    if (*current_ != *c) {
      current_ = start;
      return false;
    }
    ++current_;
  }
  return true;
}
}  // namespace common
