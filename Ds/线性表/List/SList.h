#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define ElemType int

typedef struct Node
{
 ElemType data;
 struct Node *next;

}Node,*PNode;

typedef struct List
{
    PNode first;
    PNode last;
    int size;
}List;

void InitList(List *list);
void push_back(List *list,ElemType x);
void push_front(List *list,ElemType x);

void pop_back(List *list);
void insert_val(List *list,ElemType x);
Node* find(List *list,ElemType x);
int length(List *list);
void delete_val(List *list,ElemType key);
void sort(List *list);
void resver(List *list);
void clear(List *list);
void destroy(List *list);
void show_list(List *list);

////
typedef Node* It;

Node *_buynode(ElemType x);
It begin(List *list);
It end(List *list);

void insert(List *list,It pos,ElemType x);