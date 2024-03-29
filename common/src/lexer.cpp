#include "lexer.hpp"

#include <cctype>
#include <stdexcept>

namespace common {

std::vector<Token*> Lexer::tokenize() {
  while (current_ != source_.end()) {
    if (*current_ == '+') {
      tokens_.push_back(new Token(Token::Type::Add, "+"));
      ++current_;
    } else if (*current_ == '-') {
      tokens_.push_back(new Token(Token::Type::Subtract, "-"));
      ++current_;
    } else if (*current_ == '*') {
      tokens_.push_back(new Token(Token::Type::Multiply, "*"));
      ++current_;
    } else if (*current_ == '/') {
      tokens_.push_back(new Token(Token::Type::Divide, "/"));
      ++current_;
    } else if (*current_ == '%') {
      tokens_.push_back(new Token(Token::Type::Modulus, "%"));
      ++current_;
    } else if (*current_ == '?') {
      tokens_.push_back(new Token(Token::Type::Print, "?"));
      ++current_;
    } else if (std::isspace(static_cast<unsigned char>(*current_))) {
      skipWhitespace();
    } else if (*current_ == '\0') {
      break;
    } else if (std::isdigit(static_cast<unsigned char>(*current_))) {
      parseNumber();
    } else if(std::isalpha(static_cast<unsigned char>(*current_))){
      parseIdentifier();
    }else{
      throw std::runtime_error("Invalid character: " + std::string(1, *current_));
    }
  }
  return tokens_;
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
}  // namespace common
