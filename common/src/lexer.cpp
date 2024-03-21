#include "lexer.hpp"

#include <stdexcept>

namespace common {

std::vector<Token*> Lexer::tokenize() {
    while (current_ != source_.end()) {
        if (*current_ == '(') {
            tokens_.push_back(new Token(Token::Type::List, "("));
            ++current_;
        } else if (*current_ == ')') {
            tokens_.push_back(new Token(Token::Type::List, ")"));
            ++current_;
        } else if (*current_ == '{') {
            tokens_.push_back(new Token(Token::Type::Object, "{"));
            ++current_;
        } else if (*current_ == '}') {
            tokens_.push_back(new Token(Token::Type::Object, "}"));
            ++current_;
        } else if (*current_ == '[') {
            tokens_.push_back(new Token(Token::Type::List, "["));
            ++current_;
        } else if (*current_ == ']') {
            tokens_.push_back(new Token(Token::Type::List, "]"));
            ++current_;
        } else if (*current_ == ' ' || *current_ == '\t' || *current_ == '\n') {
            ++current_;
        } else if (*current_ == '"') {
            std::string value;
            ++current_;
            while (*current_ != '"') {
                if (*current_ == '\\') {
                    ++current_;
                    if (*current_ == 'n') {
                        value += '\n';
                    } else if (*current_ == 't') {
                        value += '\t';
                    } else if (*current_ == 'r') {
                        value += '\r';
                    } else if (*current_ == 'b') {
                        value += '\b';
                    } else if (*current_ == 'f') {
                        value += '\f';
                    } else if (*current_ == '\\') {
                        value += '\\';
                    } else if (*current_ == '"') {
                        value += '"';
                    }
                } else {
                    value += *current_;
                }
                ++current_;
            }
            ++current_;
            tokens_.push_back(new Token(Token::Type::String, value));
        } else if (*current_ == ':') {
            tokens_.push_back(new Token(Token::Type::Instruction, ":"));
            ++current_;
        } else if (*current_ == ',') {
            tokens_.push_back(new Token(Token::Type::List, ","));
            ++current_;
        } else if (*current_ == ';') {
            tokens_.push_back(new Token(Token::Type::List, ";"));
            ++current_;
        } else if (*current_ == '!') {
            tokens_.push_back(new Token(Token::Type::Logical, "!"));
            ++current_;
        } else if (*current_ == '~') {
            tokens_.push_back(new Token(Token::Type::Logical, "~"));
            ++current_;
        } else if (*current_ == '+') {
            tokens_.push_back(new Token(Token::Type::Instruction, "+"));
            ++current_;
        } else if (*current_ == '-') {
            tokens_.push_back(new Token(Token::Type::Instruction, "-"));
            ++current_;
        } else if (*current_ == '*') {
            tokens_.push_back(new Token(Token::Type::Instruction, "*"));
            ++current_;
        } else if (*current_ == '/') {
            tokens_.push_back(new Token(Token::Type::Instruction, "/"));
            ++current_;
        } else if (*current_ == '%') {
            tokens_.push_back(new Token(Token::Type::Instruction, "%"));
            ++current_;
        } else if (*current_ == '^') {
            tokens_.push_back(new Token(Token::Type::Instruction, "^"));
            ++current_;
        } else if (*current_ == '&') {
            tokens_.push_back(new Token(Token::Type::Instruction, "&"));
            ++current_;
        } else if (*current_ == '|') {
            tokens_.push_back(new Token(Token::Type::Instruction, "|"));
            ++current_;
        } else if (*current_ == '<') {
            tokens_.push_back(new Token(Token::Type::Instruction, "<"));
            ++current_;
        } else if (*current_ == '>') {
            tokens_.push_back(new Token(Token::Type::Instruction, ">"));
            ++current_;
        } else if (*current_ == '=') {
            tokens_.push_back(new Token(Token::Type::Instruction, "="));
            ++current_;
        } else if (*current_ == '?') {
            tokens_.push_back(new Token(Token::Type::Instruction, "?"));
            ++current_;
        } else if (*current_ == '$') {
            tokens_.push_back(new Token(Token::Type::Instruction, "$"));
            ++current_;
        } else if (*current_ == '@') {
            tokens_.push_back(new Token(Token::Type::Instruction, "@"));
            ++current_;
        } else if (*current_ >= '0' && *current_ <= '9') {
            std::string value;
            while (*current_ >= '0' && *current_ <= '9') {
                value += *current_;
                ++current_;
            }
            tokens_.push_back(new Token(Token::Type::Number, value));
        } else {
            throw std::runtime_error("Unrecognized token: " + std::string(1, *current_));
        }
    }
    return tokens_;
}
}  // namespace common