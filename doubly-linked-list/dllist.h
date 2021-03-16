#pragma once

#define TYPE int
#define PLACE_HOLDER "%d "

typedef enum
{
    OK,
    ERROR
} STATUS;

typedef struct _node
{
    TYPE number;
    struct _node *prevNode;
    struct _node *nextNode;
} NODE;

typedef struct
{
    NODE *head;
    NODE *tail;
    int length;
} DLLIST;

void dllistInit(DLLIST *dllist);
void dllistClear(DLLIST *dllist);
void dllistAppend(DLLIST *dllist, TYPE value);
void dllistPrepend(DLLIST *dllist, TYPE value);
void dllistPrint(DLLIST *dllist);
NODE *dllistGetNodeByIndex(DLLIST *dllist, int index);
void dllistDeleteNode(DLLIST *dllist, NODE *theNode);
void dllistInsertNode(DLLIST *dllist, NODE *theNode, TYPE value, int direction);