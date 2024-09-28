#pragma once
#include <stdlib.h>
#include <cassert>
#define T int
#define MAXSIZE 20
typedef T SqList[MAXSIZE];

void Swap(T *a, T *b){
    T temp = *a;
    *a = *b;
    *b = temp;

}




int SelectMinKey(SqList &L,int k ,int n){
    T minval = L[k];
    int pos = k;
    for (int i = k+1; i < n; i++)
    {
        if(L[i]<minval){
            minval =L[i];
            pos = i;
        }
        
    }
    return pos;

}

void SelectSort(SqList &L,int n){
    for (int i = 0; i < n-1; i++)
    {
        int j = SelectMinKey(L,i,n);
        if(j!= i){
            Swap(&L[j],&L[i]);
        }
    }
    


}

//================TreeSort=============
#define MAXVALUE 0x7fffffff
int GetValue(T e[],int n ,int p){
    if(p>=n)
    return MAXVALUE;
    T value;
    if(p<n/2)//非叶子节点的情况
    {
        value = e[e[p]];

    }
    else{
        value = e[p];
    }
    return value;

}


void Select(T e[],int n ,int p){
    int i = p;
    int j = 2*p+1;
    T leftval,rightval;
    int flag =-1;
    while (i>=0&&flag)
    {
        leftval = GetValue(e,n,j);
        rightval = GetValue(e,n,j+1);
        if (leftval <= rightval)
        {
            if (j<n/2)
            {
                e[i] = e[j];
            }else{
                e[i] = j;
            }
            
        }else{
            if (j+1<n/2)
            {
                e[i] = e[j+1];
            }else{
                e[i] = j+1;

            }
        }
        if(i==0)flag++;
        i = (i-1)/2;//右子树
        j= 2*i+1;//左子树
    }
    

}
void Play(T e[],int n ,int p  ){
    int left,right;
    int leftval,rightval;
    while(p>=0){
        left = 2*p+1;
        right = 2*p+2;
        leftval = GetValue(e,n,left);
        rightval = GetValue(e,n,right);
        if(leftval <= rightval){
            if (left<n/2)
            {
                e[p]=e[left];//索引号
            }else{
                e[p]=left;//终端值
            }
        }
        else{
            if (right<n/2)
            {
                e[p]=e[right];
            }else{
                e[p]=right;
            }

        }
        --p;

    }

}

void TreeSelectSort(SqList &L, int n){
    int size = 2*n -1 ;
    T *e = (T*) malloc(sizeof(T)*size);
    assert(e!=NULL);
    int k = size / 2;
    for(int i = 0;i<n;++i )
    {
        e[k++] = L[i];
    }//给树的叶子结点赋值

    //比较排序
    int curpose = size/2-1;//第一个分支结点
    Play(e,size,curpose);
    int i = 0;
    L[i] = e[e[0]];
    ///////////

    e[e[0]] = MAXVALUE;
    for(i=1;i<n;++i)
    {
        curpose=(e[0]-1)/2;
        Select(e,size,curpose);//选择一个最小值放到0
        L[i] = e[e[0]];
        e[e[0]] = MAXVALUE;

    }
    free(e);
    e = NULL;

}

//============MergeSOrt===========
void Merge(SqList& L,SqList &TP, int left ,int mid ,int right){
    for(int i=left; i<= right ; ++i){
        TP[i] = L[i];

    }
    int s1 = left;
    int s2 = mid+1;
    int k = left;
    while (s1<=mid&&s2<=right)
    {
        if(TP[s1]<= TP[s2])
        {
            L[k++] = TP[s1++];
        }else{
            L[k++] = TP[s2++];
        }
    }//通过逐个比较 TP[s1] 和 TP[s2]，把较小的元素放入 L[k] 中，直到一个子数组的所有元素都被合并。
    while (s1<=mid)
    {
        L[k++] = TP[s1++];
    }
    while (s2<=right)
    {
        L[k++] = TP[s2++];
    }

}
void MergeSort(SqList &L, SqList &TP, int left ,int right){
    if(left>=right){
        return;
    }
    int mid = (left+right)/2;
    MergeSort(L,TP,left,mid);
    MergeSort(L,TP,mid+1,right);
    Merge(L,TP,left,mid,right);
    


}







//==============QuickSort======================
int Partition(SqList &L,int low,int high){
    T pk = L[low];//通过一个临时空间避免交换
    while(low<high){
        while(low<high && L[high]>=pk){
            high--;
        }
        L[low] = L[high];
        while (low<high&&L[low]<pk)
        {
            low++;
        }
        L[high] = L[low];
        
    }
    L[low] = pk;//枢轴点
    return low;


}
void QuickSort(SqList& L,int low, int high){
    if (low<high){
        int pkloc = Partition(L,low,high);
        QuickSort(L,low,pkloc-1);
        QuickSort(L,pkloc+1,high);
    }

}
//==============QuickSort======================


/*
void InsertSort(SqList &L,int n){
    for (int i = 1; i < n; i++)
    {
        if (L[i]<L[i-1])
        {
            Swap(&L[i],&L[i-1]);
            for (int j = i-1; j >0&&L[j]<L[j-1]; j--)
            {
                Swap(&L[j],&L[j-1]);

            }
        }
    }
}
*/


void ShellInsert(SqList &L,int n ,int dk){
    int j;
    for(int i = dk+1;i< n;i++){
        if(L[i]<L[i-dk]){
            L[0] = L[i];
            for(j = i-dk;j>0&&L[0]<L[j];j-=dk){
                L[j+dk] = L[j];
            }
            L[j+dk] = L[0];

        }

    }

}
void ShellSort(SqList &L,int n, int dlta[],int t){
    for (int k = 0; k < t; k++)
    {
        ShellInsert(L,n,dlta[k]);
    }
}


void BInsertSort(SqList &L,int n){
    for (int i = 2; i < n; i++)
    {
        L[0] = L[i];
        int low = 1;
        int high = i -1;
        while (low<=high)
        {
            int mid = (low+high)/2;
            if (L[0]>=L[mid])
            {
                low = mid+1;
            }else{
                high = mid -1;
            }
        }
        for(int j =i; j>=high+1; --j)
        {
            L[j]=L[j-1];
        }
            L[low]=L[0];
    }
}

void InsertSort(SqList &L,int n){
    int j;
    for (int i = 2; i < n; i++)
    if(L[i]<L[i-1]){
        L[0] = L[i];
        L[i] = L[i-1];
        for (j = i-2; L[0]<L[j]; --j)
            L[j+1]=L[j];
        L[j+1]=L[0];
    }
}

void TwoWayInsertSort(SqList &L,int n){
    SqList TP;
    TP[0] = L[0];
    int head,tail;
    head = tail=0;
    for (int i = 1; i < n; i++)
    {
        int j;
        if(L[i]<L[head]){//小于头则插到前面
            head = (head-1+n)%n;
            TP[head] = L[i];
        }
        else if(L[i]>TP[tail]){//大于尾则插到后面
            tail++;
            TP[tail] = L[i];
        }else{ //既不小于头也不小于尾(直接)
            tail++;
            TP[tail] = TP[tail-1];
            for(j = tail-1;L[i]<TP[(j-1+n)%n];j=(j-1+n)%n){
                TP[j] = TP[(j-1+n)%n];
            }
            TP[j]=L[i];
        }
    }
    for ( int i = 0; i < n; i++)
    {
        L[i] = TP[head];
        head = (head+1)%n;
    }
    
}

void BubbleSort(SqList &L,int n ){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
        if(L[j]>L[j+1]){
            Swap(&L[j],&L[j+1]);
        }
        }
    }
    
}