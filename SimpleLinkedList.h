#ifndef simplelinkedlist_h
#define simplelinkedlist_h

typedef struct listElement {
    void* itmPtr;
    struct listElement* next;
} listElement;

typedef struct linkedList {
    int numItems;
    struct listElement* firstItem;
    struct listElement* lastItem;
} linkedList;

linkedList* createList();
void insertAtFront(linkedList* LL, void* newItem);
void insertAtEnd(linkedList* LL, void* newItem);
void* removeFromFront(linkedList* LL);
void* removeFromEnd(linkedList* LL);
void printList(linkedList* LL, void *(*printObj)(void *));

#endif