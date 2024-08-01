#ifndef PARSER_H
#define PARSER_H

#include "../token/token.h"
#include "../node/node.h"
#include <stdio.h>
#include <stdbool.h>

struct Parser
{
    Token *tokens;
    int position;
    Node *root;
} typedef Parser;

Parser *init_parser(Token *tokens);

void free_parser(Parser *);

void parse(Parser *);

/**
 * expression =>  term
 * term => factor ((PLUS | MINUS) factor)*
 * factor => unary ((MUL | DIV) unary)*
 * unary => (PLUS | MINUS) unary | primary
 * primary => NUMBER | LPAREN expression RPAREN
 */

static Node *expression(Parser *);
static Node *term(Parser *);
static Node *factor(Parser *);
static Node *unary(Parser *);
static Node *primary(Parser *);

static bool match(Parser *, TokenType);
static bool check(Parser *, TokenType);
static Token previous_token(Parser *);
static bool parser_is_at_end(Parser *);
static Token current_token(Parser *);
static void parser_advance(Parser *);
static void parser_retreat(Parser *);

#endif
