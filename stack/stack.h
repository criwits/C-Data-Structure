#pragma once

#define PLACEHOLDER "%d "

typedef char TYPE;

typedef struct _node
{
    TYPE value;
    struct _node *next;
} NODE;

typedef struct
{
    NODE *base, *top;
    int height;
} STACK;

void stackInit(STACK *this);
void stackClear(STACK *this);
void stackPush(STACK *this, TYPE value);
TYPE stackPop(STACK *this);