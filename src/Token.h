#ifndef _TOKEN_H
#define _TOKEN_H

typedef enum {
  TOKEN_UNKNOWN_TYPE,
  TOKEN_INTEGER_TYPE,
  TOKEN_OPERATOR_TYPE,
  TOKEN_FLOAT_TYPE,
  TOKEN_STRING_TYPE,
  TOKEN_IDENTIFIER_TYPE,
} TokenType;

typedef struct {
  TokenType type;
  uint32_t startColumn;
  uint32_t length;
  char *originalStr;
  char *str;
} Token;

typedef struct {
  TokenType type;
  uint32_t startColumn;
  uint32_t length;
  char *originalStr;
  char *str;
  Token *token[0];
} OperatorToken;

#endif // _TOKEN_H
