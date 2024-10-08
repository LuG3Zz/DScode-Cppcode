#pragma once



#include<stdio.h>
#include<malloc.h>
#include<assert.h>


#define ElemType int

typedef struct  Node

{
    ElemType data;
    struct Node *prio;
    struct Node *next;

}Node,*PNode;

typedef struct List
{
    PNode first;
    PNode last;
    int size;

}List;


void InitDList(List *list);
void push_back(List *list,ElemType x);
void push_front(List *list,ElemType x);
void pop_front(List *list);
void pop_back(List *list);
void insert_val(List *list,ElemType x);
Node* find(List *list,ElemType key);
int length(List *list);
void delete_val(List *list,ElemType key);
void sort(List *list);
void resver(List *list);
void clear(List *list);
void destroy(List *list);
void show_list(List *list);
Node *_buynode(ElemType x);