#include "node.h"

Node *init_node(NodeType node_type, Token token, Node *left, Node *right)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->node_type = node_type;
    node->token = token;
    node->left = left;
    node->right = right;
    return node;
}

void free_node(Node *node)
{
    if (node->left != NULL)
    {
        free_node(node->left);
    }

    if (node->right != NULL)
    {
        free_node(node->right);
    }

    free(node);
}

void print_node(Node *node)
{
    switch (node->node_type)
    {
    case LITERAL:
        printf("%s", node->token.lexeme);
        break;
    case UNARY:
        printf("(");
        printf("%s", node->token.lexeme);
        printf(" ");
        print_node(node->left);
        printf(")");
        break;
    case BINARY:
        printf("(");
        printf("%s", node->token.lexeme);
        printf(" ");
        print_node(node->left);
        printf(" ");
        print_node(node->right);
        printf(")");
        break;
    case START:
        printf("START\n");
        print_node(node->left);
        break;
    default:
        break;
    }
}
