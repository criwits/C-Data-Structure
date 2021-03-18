#define _CRT_SECURE_NO_WARNINGS

#include "stack.h"
#include <stdio.h>

char getMatch(char pt)
{
    switch (pt) {
    case ')':
        return '(';
    case '}':
        return '{';
    case ']':
        return '[';
    default:
        return '\0';
    }
}

int main(void)
{
    // Ð´Ò»¸ö·ûºÅÆ¥Åä°É¡£
    char inputString[32];
    scanf("%s", inputString);
    char *ptr = inputString;
    STACK ptStack;
    int isMatched = 1;
    stackInit(&ptStack);
    while (*ptr != '\0') {
        switch (*ptr) {
        case '[':
        case '{':
        case '(':
            stackPush(&ptStack, *ptr);
            break;
        case ')':
        case '}':
        case ']':
            if (stackPop(&ptStack) != getMatch(*ptr)) {
                isMatched = 0;
            }
            break;
        default:
            break;
        }
        ptr++;
    }
    if (ptStack.height != 0) {
        isMatched = 0;
    }
    printf("%d\n", isMatched);
    return 0;
}