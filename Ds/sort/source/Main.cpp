#include <stdio.h>

#include "../Sort.h"
#include "../Heap.h"
//#define USE_ZERO_SPACE 

int main(int argc, char const *argv[])
{
    #ifdef USE_ZERO_SPACE
    SqList L = {0,49,38,65,97,76,13,27,49};
    int n = 9;
    #else
    SqList L = {49,38,65,97,76,13,27,49};
    int n = 8;
    #endif

    SqList TP;
    MergeSort(L,TP,0,n-1);
    //HeapSort(L,n);
    // TreeSelectSort(L,n);
    // SelectSort(L,n);
    //QuickSort(L,0,7);
    //BubbleSort(L,n);
    // InsertSort(L,6);
    //BInsertSort(L,n);
    // TwoWayInsertSort(L,n);

    //===希尔排序===
    // int dlta[] ={5,3,2,1};
    // int t = sizeof(dlta)/sizeof(int);
    // ShellSort(L,n,dlta,t);
    //===end===

    #ifdef USE_ZERO_SPACE
    for (int  i = 1; i < n; i++)
    {
        printf("%d ",L[i]);
    }
    #else
    for (int  i = 0; i < n; i++)
    {
        printf("%d ",L[i]);
    }
    #endif

    

    return 0;
}
