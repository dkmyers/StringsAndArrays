#include "StringsAndArrays.h"


int main()
{
    //Initalizers
    struct link* head;

    //
    head = createLinkedListFromString("This is a very long string");
    printList(head);

    //
    destroy_linked_list(&head);
    printList(head);
    return 0;
}