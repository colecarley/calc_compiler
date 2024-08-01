
#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include "../token/token.h"

enum NodeType
{
    LITERAL,
    UNARY,
    BINARY,
    START
} typedef NodeType;

struct Node
{
    NodeType node_type;
    Token token;
    struct Node *left;
    struct Node *right;
} typedef Node;

Node *init_node(NodeType node_type, Token token, Node *left, Node *right);

void free_node(Node *node);

void print_node(Node *node);

#endif