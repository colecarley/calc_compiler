#include <stdio.h>
#include "./lexer/lexer.h"
#include "./parser/parser.h"
#include "./node/node.h"
#include "./token/token.h"
#include "./interpreter/interpreter.h"
#include <string.h>

#define MAX_INPUT_SIZE 30

int main()
{
    while (true)
    {

        char input[MAX_INPUT_SIZE];
        printf(">");
        fgets(input, MAX_INPUT_SIZE, stdin);

        Lexer *lexer = init_lexer(input);

        lex(lexer);
        // print_tokens(lexer);

        Token *tokens = lexer->tokens;
        int token_count = lexer->token_count;

        Parser *parser = init_parser(tokens);

        // printf("foobar %d", parser->tokens[0].type);
        parse(parser);

        Node *root = parser->root;

        // print_node(root);

        Interpreter *interpreter = init_interpreter(root);

        interpret(interpreter);

        printf("Result: %d\n", interpreter->result);

        free_lexer(lexer);
        free_parser(parser);
        free_interpreter(interpreter);
    }
    return 0;
}
