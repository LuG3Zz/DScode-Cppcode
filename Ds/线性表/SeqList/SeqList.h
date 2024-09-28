#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#define SEQLIST_INIT_SIZE 8
#define INC_SIZE          3
typedef int ElemType;

typedef struct SeqList{
    ElemType *base;
    int capacity;
    int size;
}SeqList;

void InitSeqList(SeqList *list);
void push_back(SeqList *list,ElemType x);
void push_front(SeqList *list,ElemType x);
void pop_back(SeqList *list);
void insert_pos(SeqList *list,int pos , ElemType x);
int find(SeqList *list,ElemType x);
int length(SeqList *list);

void merge(SeqList *lt,SeqList *la,SeqList *lb);
void show_list(SeqList *list);



