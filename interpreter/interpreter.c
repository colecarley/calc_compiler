#include "interpreter.h"

Interpreter *init_interpreter(Node *root)
{
    Interpreter *interpreter = (Interpreter *)malloc(sizeof(Interpreter));
    interpreter->root = root;
    interpreter->result = 0;
    return interpreter;
}

void free_interpreter(Interpreter *interpreter)
{
    free_node(interpreter->root);
    free(interpreter);
}

void interpret(Interpreter *interpreter)
{
    int result = interpret_node(interpreter->root->left);
    interpreter->result = result;
}

static int interpret_node(Node *node)
{
    switch (node->node_type)
    {
    case LITERAL:
        return interpret_literal(node);
        break;
    case UNARY:
        return interpret_unary(node);
        break;
    case BINARY:
        return interpret_binary(node);
        break;
    default:
        printf("Unknown node type: %d\n", node->node_type);
        exit(1);
        break;
    }
}

static int interpret_literal(Node *node)
{
    return atoi(node->token.lexeme);
}

static int interpret_unary(Node *node)
{
    int result = interpret_node(node->left);
    if (strcmp(node->token.lexeme, "-") == 0)
    {
        return -result;
    }
    else
    {
        printf("Unknown unary operator: %s\n", node->token.lexeme);
        exit(1);
    }
}

static int interpret_binary(Node *node)
{
    int left = interpret_node(node->left);
    int right = interpret_node(node->right);
    switch (node->token.type)
    {
    case PLUS:
        return left + right;
    case MINUS:
        return left - right;
    case STAR:
        return left * right;
    case SLASH:
        return left / right;
    default:
        printf("Unknown binary operator: %s\n", node->token.lexeme);
        exit(1);
    }
}