
#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "../node/node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Interpreter {
    Node *root;
    int result;
} typedef Interpreter;

Interpreter *init_interpreter(Node *root);

void free_interpreter(Interpreter *interpreter);

void interpret(Interpreter *interpreter);

static int interpret_node(Node *node);

static int interpret_binary(Node *node);

static int interpret_unary(Node *node);

static int interpret_literal(Node *node);

#endif