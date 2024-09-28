#include "StaticList.h"


void InitSList(StaticList &space){
    for (int i = 1; i < MAX_SIZE-1; i++)
    {
        space[i].cur = i+1;
    }
    space[MAX_SIZE-1].cur = 0;

    space[0].cur =-1;

}
int Malloc_SL(StaticList &space){
    int i = space[1].cur;
    if(space[1].cur!=0)space[1].cur = space[i].cur;
    return i;
}
void Free_SL(StaticList &space,int k){
    space[k].cur = space[1].cur;
    space[1].cur = k;

}

void Insert(StaticList &space, ElemType x){
    int i = Malloc_SL(space);
    if(i==0){
        printf("申请结点失败\n");
        return;
    }
    space[i].data=x;
    if(space[0].cur ==-1){
        space[i].cur = -1;
    }else{
        space[i].cur = space[0].cur;
    }
        space[0].cur = i;

}


void Delete(StaticList &space){
    if(space[0].cur ==-1)return;
    int i = space[0].cur;
    space[0].cur = space[i].cur;
    Free_SL(space,i);
   


}

void ShowSList(StaticList &space){
    int i = space[0].cur;
    while (i!=-1)
    {
        printf("%c-->",space[i].data);
        i = space[i].cur;//p=p->next;
    }
    printf("NULL.");

}