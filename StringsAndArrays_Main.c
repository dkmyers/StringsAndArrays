#include <stdio.h>
#include "StringsAndArrays.h"


int main()
{
    struct link* test = create_link('z');
    insertAtEndOfList_ByValue(test, 'd');
    insertAtEndOfList_ByValue(test, 'g');
    insertAtEndOfList_ByValue(test, 'q');
    insertAtEndOfList_ByValue(test, 'w');
    insertAtEndOfList_ByValue(test, 'w');
    printList(test);
    destroy_linked_list(&test);
    printList(test);
    return 0;
}