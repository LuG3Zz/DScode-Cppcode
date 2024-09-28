#pragma once

#include "Sort.h"
#include <stdio.h>

void siftDown(T heap[],int n,int p){
    int i = p;
    int j = 2*i+1; // p结点的左孩子
    while (j<n)
    {
        if (j<n-1&&heap[j]>heap[j+1])//j指向p结点中的最小孩子
        {
            j++;
        }
        if(heap[i]<=heap[j]){
            break;
        }else{
            Swap(&heap[j],&heap[i]);
            i= j;//交换后调整
            j=2*i+1;
        }
    }
}

T RemoveMinKey(T heap[],int n){
    T key = heap[0];
    heap[0] = heap[n];
    siftDown(heap,n,0);
    return key;

}


void HeapSort(SqList &L , int n ){
    T *heap = (T*) malloc(sizeof(T)*n);
    assert(heap!=NULL);
    for (int i = 0; i < n; i++)
    {
        heap[i] = L[i];
    }
    // for(int i=0;i<n;++i){
    //     printf("%d ",heap[i]);
    // }
    // printf("\n");
    int curpos = n/2-1 ;//最后一个节点的父母节点
    while (curpos >=0)
    {
        siftDown(heap,n,curpos);
        curpos --;
    }
    // for(int i=0;i<n;++i){
    //     printf("%d ",heap[i]);
    // }
    // printf("\n");
    for (int i = 0; i < n; i++)
    {
        L[i] = RemoveMinKey(heap,n-i-1);
    }
    
    
    
}


