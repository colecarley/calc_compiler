#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>

enum TokenType
{
    // Single-character tokens
    LPAREN,
    RPAREN,
    MINUS,
    PLUS,
    SLASH,
    STAR,
    // Literals
    NUMBER,

    // EOF
    END,
} typedef TokenType;

struct Token
{
    TokenType type;
    char *lexeme;
} typedef Token;

Token create_token(TokenType type, char *lexeme);

void print_token(Token token);

#endif
