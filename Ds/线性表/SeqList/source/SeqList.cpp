#include "../SeqList.h"


bool Inc(SeqList *list){
    ElemType *newbase = (ElemType*)realloc(list->base,sizeof(ElemType)*(list->capacity+INC_SIZE));
    if(newbase == NULL){
        printf("内存已满");
        return false;
    }
    list->base = newbase;
    list->capacity += INC_SIZE;
    return true;

}

void InitSeqList(SeqList *list){
    list->base = (ElemType*) malloc(sizeof(ElemType)*SEQLIST_INIT_SIZE);
    assert(list->base!=NULL);
    list->capacity = SEQLIST_INIT_SIZE;
    list->size =0;
    
}

void push_back(SeqList *list,ElemType x){
    if (list->size >= list->capacity && !Inc(list))
    {
        printf("顺序表已满！无法插入\n");
        return;
    }
    list->base[list->size]=x;
    list->size++;
    

}
void push_front(SeqList *list,ElemType x){
    if (list->size >= list->capacity&&!Inc(list))
    {
        printf("顺序表已满！无法插入\n");
        return;

    }
    for (int i = list->size; i >0; i--)
    {
        list->base[i] = list->base[i-1];
    }
    list->base[0]=x;
    list->size++;
}

void pop_back(SeqList *list){
    if (list->size == 0)
    {
        printf("顺序表为空，不能尾部删除数据\n");
        return;
    }
    list->size--;
}
void pop_front(SeqList *list){
    if (list->size == 0)
    {
        printf("顺序表为空，不能头部删除数据\n");
        return;
    }
    for (int i = 0; i <list->size-1; i++)
    {
        list->base[i] = list->base[i+1];
    }
    list->size--;
}

void insert_pos(SeqList *list,int pos , ElemType x){
    if(pos<0 || pos> list->size){
        printf("插入数据的位置非法,不能插入数据\n");
    }
    if (list->size >= list->capacity&&!Inc(list)){
        printf("顺序表满无法插入");

    }
        for (int i = list->size; i >pos;i--)
        {
            list->base[i] = list->base[i-1];
        }
        list->base[pos] = x;
        list->size++;
}
int find(SeqList *list,ElemType x){
    for (int i = 0; i < list->size; i++)
    {
        if(list->base[i] == x)return i;
    }
    return -1;
}
int length(SeqList *list){
    return list->size;
}


void merge(SeqList *lt,SeqList *la,SeqList *lb){
    lt->capacity = la->size+lb->size;
    lt->base = (ElemType*) malloc(sizeof(ElemType)*lt->capacity);
    assert(lt->base !=NULL);
    int ia = 0;
    int ib = 0;
    int ic = 0;
    while (ia<la->size && ib<lb->size)
    {
        if (la->base[ia]<lb->base[ib])
        {
            lt->base[ic++] = la->base[ia++];
        }else{
            lt->base[ic++] = lb->base[ib++];
        }
    }
    while (ia<la->size)
    {
        lt->base[ic++] = la->base[ia++];
        
    }
    while (ib<lb->size)
    {
        lt->base[ic++] = lb->base[ib++];
        
    }
    lt->size = la->size+lb->size;
    
    

}

void show_list(SeqList *list){
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ",list->base[i]);
    }
    printf("\n");
}