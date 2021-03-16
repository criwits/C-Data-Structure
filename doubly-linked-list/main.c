#include "dllist.h"
#include <stdio.h>

int main(void)
{
    // A Demo Program.
    DLLIST list;
    dllistInit(&list);
    dllistAppend(&list, 45);
    dllistAppend(&list, 14);
    dllistPrepend(&list, 11);
    dllistAppend(&list, 191);
    dllistAppend(&list, 98);
    dllistAppend(&list, 10);
    // Then it should be 11 45 14 191 98 10.
    dllistPrint(&list);
    printf("\n");
    // Remove `45`.
    dllistDeleteNode(&list, dllistGetNodeByIndex(&list, 1));
    dllistPrint(&list);
    printf("\n");
    // Insert 23 after `191`.
    dllistInsertNode(&list, dllistGetNodeByIndex(&list, 2), 23, 1);
    dllistPrint(&list);
    printf("\n");
    // Insert 46 before `11`. (The same as `prepend`..)
    dllistInsertNode(&list, dllistGetNodeByIndex(&list, 0), 46, 0);
    dllistPrint(&list);
    printf("\n");
    // Clear memory.
    dllistClear(&list);
    return 0;
}