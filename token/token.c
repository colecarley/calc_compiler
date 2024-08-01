#include "token.h"

Token create_token(TokenType type, char *lexeme)
{
    Token token;
    token.type = type;
    token.lexeme = lexeme;
    return token;
}

void print_token(Token token)
{
    printf("Token: %d, Lexeme: %s\n", token.type, token.lexeme);
}