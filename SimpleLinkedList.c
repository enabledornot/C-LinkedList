#include <stdlib.h>
#include <string.h>
#include "SimpleLinkedList.h"

linkedList* createList() {
    linkedList* newList = malloc(sizeof(linkedList));
    memset(newList, 0, sizeof(linkedList));
}

listElement* __getElement(void* elementPtr) {
    listElement* newElement = malloc(sizeof(listElement));
    memset(newElement, 0, sizeof(listElement));
    newElement->itmPtr = elementPtr;
    return newElement;
}

void insertIntoFront(linkedList* LL, void* newItem) {
    listElement* newElement = __getElement(newItem);
    if(LL->firstItem==NULL) {
        LL->firstItem = newElement;
        LL->lastItem = newElement;
    }
    else {
        newElement->next = LL->firstItem;
        LL->firstItem = newElement;
    }
    LL->numItems+=1;
}

void insertAtEnd(linkedList* LL, void* newItem) {
    listElement* newElement = __getElement(newItem);
    if(LL->firstItem==NULL) {
        LL->firstItem = newElement;
        LL->lastItem = newElement;
    }
    else {
        LL->lastItem->next = newElement;
        LL->lastItem = newElement;
    }
    LL->numItems+=1;
}

void* removeFromFront(linkedList* LL) {
    listElement* removedElement = LL->firstItem;
    if(LL->firstItem!=NULL) {
        LL->firstItem = LL->firstItem->next;
    }
    return removedElement->itmPtr;
}