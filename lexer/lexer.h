#ifndef LEXER_H
#define LEXER_H

#include "../token/token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Lexer
{
    char *source;
    int source_length;
    int current_position;
    int token_count;
    Token *tokens;
} typedef Lexer;

Lexer *init_lexer(char *source);

void free_lexer(Lexer *lexer);

void lex(Lexer *lexer);

void print_tokens(Lexer *);

static char current_char(Lexer *);

static void lexer_advance(Lexer *);

static void lexer_retreat(Lexer *);

static void add_token(Lexer *, TokenType type, char *lexeme);

static int lexer_is_at_end(Lexer *);

static bool is_digit(char c);

static void handle_digit(Lexer *);

#endif