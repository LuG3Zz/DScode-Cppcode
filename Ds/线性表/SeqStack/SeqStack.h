#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

#define ElemType char

#define STACK_INIT_SIZE 8
#define STACK_INC_SIZE 3

typedef struct SeqStack
{
    ElemType *base;
    int capacity;
    int top;
}SeqStack;

void InitStack(SeqStack *s);
bool IsFull(SeqStack *S);
bool IsEmpty(SeqStack *S);
void Push(SeqStack *s ,ElemType x);
void Pop(SeqStack *s);
bool GetTop(SeqStack *s,ElemType *v);
int Length(SeqStack *s);
void Clear(SeqStack *s);
void Destroy(SeqStack *s);
void Show(SeqStack *s);
void Print(SeqStack *s);



