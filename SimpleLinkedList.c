#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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

void insertAtFront(linkedList* LL, void* newItem) {
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
    if(LL->firstItem==NULL) {
        return NULL;
    }
    listElement* removedElement = LL->firstItem;
    if(LL->firstItem==LL->lastItem) {
        LL->firstItem = NULL;
        LL->lastItem = NULL;
    }
    else {
        LL->firstItem = LL->firstItem->next;
    }
    void* removedItem = removedElement->itmPtr;
    LL->numItems-=1;
    free(removedElement);
    return removedItem;
}

void* removeFromEnd(linkedList* LL) {
    if(LL->firstItem==NULL) {
        return NULL;
    }
    listElement* removedElement = LL->lastItem;
    if(LL->firstItem==LL->lastItem) {
        LL->firstItem = NULL;
        LL->lastItem = NULL;
    }
    else {
        listElement* prevPtr = LL->firstItem;
        while(prevPtr->next!=removedElement) {
            prevPtr = prevPtr->next;
        }
        if(removedElement==LL->lastItem) {
            LL->lastItem = prevPtr;
        }
        prevPtr->next = NULL;
    }
    void* removedItem = removedElement->itmPtr;
    LL->numItems-=1;
    free(removedElement);
    return removedItem;
}

void printList(linkedList* LL, void *(*printObj)(void *)) {
    listElement* listPtr = LL->firstItem;
    int cnt = 0;
    printf("PRINTING LIST\n");
    while(listPtr!=NULL) {
        printf("%d - ",cnt);
        printObj(listPtr->itmPtr);
        printf("\n");
        cnt+=1;
        listPtr = listPtr->next;
    }
}