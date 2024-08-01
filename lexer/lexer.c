#include "lexer.h"

void lex(Lexer *lexer)
{
    while (true)
    {
        if (lexer_is_at_end(lexer) == 1)
        {
            add_token(lexer, END, "EOF");
            break;
        }

        switch (current_char(lexer))
        {
        case '+':
            add_token(lexer, PLUS, "+");
            break;
        case '-':
            add_token(lexer, MINUS, "-");
            break;
        case '*':
            add_token(lexer, STAR, "*");
            break;
        case '/':
            add_token(lexer, SLASH, "/");
            break;
        case '(':
            add_token(lexer, LPAREN, "(");
            break;
        case ')':
            add_token(lexer, RPAREN, ")");
            break;
        default:
            if (is_digit(current_char(lexer)))
            {
                handle_digit(lexer);
            }
        }

        lexer_advance(lexer);
    }
}

Lexer *init_lexer(char *source)
{
    Lexer *lexer = malloc(sizeof(Lexer));
    lexer->source = source;
    lexer->source_length = strlen(source);
    lexer->current_position = 0;
    lexer->token_count = 0;
    lexer->tokens = malloc(sizeof(Token) * (strlen(source) + 1));
    return lexer;
}

void free_lexer(Lexer *lexer)
{
    free(lexer->tokens);
    free(lexer);
}

static bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

static void handle_digit(Lexer *lexer)
{
    char *lexeme = malloc(sizeof(char) * 10); // 10 is arbitrary
    int position = 0;
    while (is_digit(current_char(lexer)))
    {
        if (position > 10)
        {
            printf("Number too long\n");
            exit(1);
        }
        lexeme[position] = current_char(lexer);
        position++;
        lexer_advance(lexer);
        if (lexer_is_at_end(lexer))
        {
            break;
        }
    }

    lexer_retreat(lexer);
    add_token(lexer, NUMBER, lexeme);
}

static char current_char(Lexer *lexer)
{
    return lexer->source[lexer->current_position];
}

static void lexer_advance(Lexer *lexer)
{
    lexer->current_position++;
}

static void lexer_retreat(Lexer *lexer)
{
    lexer->current_position--;
}

static void add_token(Lexer *lexer, TokenType type, char *lexeme)
{
    Token token = create_token(type, lexeme);
    lexer->tokens[lexer->token_count] = token;
    lexer->token_count++;
}

static int lexer_is_at_end(Lexer *lexer)
{
    return lexer->current_position >= lexer->source_length;
}

void print_tokens(Lexer *lexer)
{
    for (int i = 0; i < lexer->token_count; i++)
    {
        print_token(lexer->tokens[i]);
    }
}