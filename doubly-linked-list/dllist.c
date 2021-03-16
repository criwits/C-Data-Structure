#include "dllist.h"
#include <stdio.h>
#include <malloc.h>

// Private:
void dllist_destory(NODE *node)
{
    if (node->nextNode != NULL) {
        dllist_destory(node->nextNode);
    }
    free(node);
}

void dllist_give_value(NODE *node, TYPE value)
{
    node->number = value;
}

void dllist_print(NODE *node)
{
    if (node->prevNode != NULL) {
        dllist_print(node->prevNode);
    }
    printf(PLACE_HOLDER, node->number);
}

NODE *dllist_get_next_node(NODE *node, int remaining)
{
    if (remaining == 0) {
        return node;
    }
    return dllist_get_next_node(node->nextNode, remaining - 1);
}

NODE *dllist_get_prev_node(NODE *node, int remaining)
{
    if (remaining == 0) {
        return node;
    }
    return dllist_get_prev_node(node->prevNode, remaining - 1);
}

// Public:
void dllistInit(DLLIST *dllist)
{
    dllist->head = NULL;
    dllist->tail = NULL;
    dllist->length = 0;
}

void dllistClear(DLLIST *dllist)
{
    dllist_destory(dllist->head);
    dllistInit(dllist);
}

void dllistPrint(DLLIST *dllist)
{
    if (dllist->head == NULL) {
        printf("<Empty List>");
        return;
    }
    dllist_print(dllist->tail);
}

void dllistAppend(DLLIST *dllist, TYPE value)
{
    // if `dllist` is empty then we need to malloc a new space for the very first value.
    if (dllist->tail == NULL) {
        dllist->head = (NODE *)malloc(sizeof(NODE));
        dllist->tail = dllist->head;
        dllist->tail->nextNode = NULL;
        dllist->tail->prevNode = NULL;
        dllist->tail->number = value;
    } else {
        dllist->tail->nextNode = (NODE *)malloc(sizeof(NODE));
        dllist->tail->nextNode->number = value;
        dllist->tail->nextNode->nextNode = NULL;
        dllist->tail->nextNode->prevNode = dllist->tail;
        dllist->tail = dllist->tail->nextNode;
    }
    dllist->length++;
}

void dllistPrepend(DLLIST *dllist, TYPE value)
{
    // if `dllist` is empty then we need to malloc a new space for the very first value.
    if (dllist->head == NULL) {
        dllist->head = (NODE *)malloc(sizeof(NODE));
        dllist->tail = dllist->head;
        dllist->tail->nextNode = NULL;
        dllist->tail->prevNode = NULL;
        dllist->tail->number = value;
    } else {
        dllist->head->prevNode = (NODE *)malloc(sizeof(NODE));
        dllist->head->prevNode->number = value;
        dllist->head->prevNode->prevNode = NULL;
        dllist->head->prevNode->nextNode = dllist->head;
        dllist->head = dllist->head->prevNode;
    }
    dllist->length++;
}

NODE *dllistGetNodeByIndex(DLLIST *dllist, int index)
{
    if (index < 0 || index >= dllist->length) {
        return NULL;
    }
    if (index <= dllist->length / 2) {
        return dllist_get_next_node(dllist->head, index);
    } else {
        return dllist_get_prev_node(dllist->tail, dllist->length - index - 1);
    }
}

void dllistDeleteNode(DLLIST *dllist, NODE *theNode)
{
    theNode->prevNode->nextNode = theNode->nextNode;
    theNode->nextNode->prevNode = theNode->prevNode;
    free(theNode);
    dllist->length--;
}

void dllistInsertNode(DLLIST *dllist, NODE *theNode, TYPE value, int direction)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->number = value;
    if (direction) {
        temp->prevNode = theNode;
        temp->nextNode = theNode->nextNode;
        theNode->nextNode = temp;
        if (temp->nextNode != NULL) {
            temp->nextNode->prevNode = temp;
        }
    } else {
        temp->nextNode = theNode;
        temp->prevNode = theNode->prevNode;
        theNode->prevNode = temp;
        if (temp->prevNode != NULL) {
            temp->prevNode->nextNode = temp;
        }
    }
    dllist->length++;
}