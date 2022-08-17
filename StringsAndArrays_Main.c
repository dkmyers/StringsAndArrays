#include "StringsAndArrays.h"


int main()
{
    //Initalizers
    struct link* head;

    //
    head = createLinkedListFromString("I am writing a very long string which will turn into a linked list");
    printList(head);
    bubbleSortLinkedList(&head);
    //
    printList(head);
    destroy_linked_list(&head);
    printList(head);
    return 0;
}