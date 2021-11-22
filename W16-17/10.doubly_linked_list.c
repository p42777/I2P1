#include <stdio.h>
#include <stdlib.h>

struct dl_node {
    int data;
    struct dl_node *prev;
    struct dl_node *next;
};
typedef struct dl_node DL_Node;

struct dl_list {
    DL_Node *firstNode;
    DL_Node *lastNode;
};
typedef struct dl_list DL_List;

void insertAfter(DL_List *list, DL_Node *node, DL_Node *newNode)
{

}

void insertBefore(DL_List *list, DL_Node *node, DL_Node *newNode)
{

}

void insertBeginning(DL_List *list, DL_Node *newNode)
{

}

void insertEnd(DL_List *list, DL_Node *newNode)
{

}

DL_Node *createNewNode(int data)
{
    DL_Node *p;
    p = (DL_Node*) malloc(sizeof(DL_Node));
    p->data = data;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void showList(DL_List *list)
{
    DL_Node *p = list->firstNode;
    while (p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
void showListReverse(DL_List *list)
{

}
void removeNode(DL_List *list, DL_Node *node)
{

}
void freeList(DL_List *list)
{
    DL_Node *p = list->firstNode;
    while (p != NULL) {
        p = p->next;
        if (p!=NULL)
            free(p->prev);
        else
            free(list->lastNode);
    }
    free(list);
}
int main(void){
    DL_List *dll = NULL;

    dll = (DL_List*) malloc(sizeof(DL_List));

    dll->firstNode = NULL;
    dll->lastNode = NULL;

    insertBeginning(dll, createNewNode(14));
    insertBeginning(dll, createNewNode(13));
    insertBeginning(dll, createNewNode(12));
    insertBeginning(dll, createNewNode(11));
    insertBeginning(dll, createNewNode(10));

    insertEnd(dll, createNewNode(20));
    insertEnd(dll, createNewNode(21));
    insertEnd(dll, createNewNode(22));
    insertEnd(dll, createNewNode(23));
    insertEnd(dll, createNewNode(24));

    showList(dll);
    showListReverse(dll);

    removeNode(dll, dll->firstNode);
    removeNode(dll, dll->lastNode);
    showList(dll);

    freeList(dll);

    return 0;
}