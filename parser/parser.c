#include "parser.h"

Parser *init_parser(Token *tokens)
{
    Parser *parser = (Parser *)malloc(sizeof(Parser));
    parser->tokens = tokens;
    parser->position = 0;
    parser->root = init_node(START, tokens[0], NULL, NULL);
    return parser;
}

void free_parser(Parser *parser)
{
    free(parser);
}

void parse(Parser *parser)
{
    parser->root->left = expression(parser);
    if (!parser_is_at_end(parser))
    {
        printf("Expected end of input\n");
        exit(1);
    }
}

static Node *expression(Parser *parser)
{
    return term(parser);
}

static Node *term(Parser *parser)
{
    Node *node = factor(parser);

    while (match(parser, PLUS) || match(parser, MINUS))
    {
        Token operator= previous_token(parser);
        Node *right = factor(parser);
        node = init_node(BINARY, operator, node, right);
    }

    return node;
}

static Node *factor(Parser *parser)
{
    Node *node = unary(parser);

    while (match(parser, STAR) || match(parser, SLASH))
    {
        Token operator= previous_token(parser);
        Node *right = unary(parser);
        node = init_node(BINARY, operator, node, right);
    }

    return node;
}

static Node *unary(Parser *parser)
{
    if (match(parser, MINUS))
    {
        Token operator= previous_token(parser);
        Node *node = unary(parser);
        return init_node(UNARY, operator, node, NULL);
    }
    else
    {
        return primary(parser);
    }
}

static Node *primary(Parser *parser)
{
    if (match(parser, NUMBER))
    {
        return init_node(LITERAL, previous_token(parser), NULL, NULL);
    }
    else if (match(parser, LPAREN))
    {
        Node *node = expression(parser);
        if (match(parser, RPAREN))
        {
            return node;
        }
        else
        {
            printf("Expected right paren\n");
            exit(1);
        }
    }
    else
    {
        printf("Expected number or left paren\n");
        exit(1);
    }
}

static Token current_token(Parser *parser)
{
    return parser->tokens[parser->position];
}

static bool match(Parser *parser, TokenType type)
{
    if (current_token(parser).type == type)
    {
        parser_advance(parser);
        return true;
    }

    return false;
}

static bool check(Parser *parser, TokenType type)
{
    return current_token(parser).type == type;
}

static void parser_advance(Parser *parser)
{
    parser->position++;
}

static void parser_retreat(Parser *parser)
{
    parser->position--;
}

static Token previous_token(Parser *parser)
{
    return parser->tokens[parser->position - 1];
}

static bool parser_is_at_end(Parser *parser)
{
    return current_token(parser).type == END;
}