#pragma once

#include <stdio.h>

#define MAX_SIZE 20
#define ElemType char


typedef struct ListNode
{
    ElemType data;
    int cur;
}ListNode;


typedef ListNode StaticList[MAX_SIZE];

int Malloc_SL(StaticList &space);
void Free_SL(StaticList &space,int k);
void InitSList(StaticList &space);
void Insert(StaticList &space,ElemType x);
void Delete(StaticList &space);

void ShowSList(StaticList &SL);