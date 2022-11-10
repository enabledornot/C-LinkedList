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
void insertIntoFront(linkedList* LL, void* newItem);
void insertAtEnd(linkedList* LL, void* newItem);

#endif