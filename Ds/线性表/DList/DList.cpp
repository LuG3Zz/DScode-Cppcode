#include "DList.h"


Node *_buynode(ElemType x){
    Node* s = (Node*)malloc(sizeof(Node));
    assert(s!=NULL);
    s->data = x;
    s->next = NULL;
    s->prio = NULL;
    return s;
};
void InitDList(List *list){
    Node *s = (Node *)malloc(sizeof(Node));
    assert(s!=NULL);
    list->first = list->last =s ;
    list->last->next = NULL;
    list->first->prio = NULL;
    list->size = 0;

}

void push_back(List *list,ElemType x){
    Node *s = _buynode(x);
    s->prio = list->last;
    list->last->next = s;
    list->last =s ;
    list->size++;

};
void push_front(List *list,ElemType x){
    Node *s = _buynode(x);
    if(list->first == list->last){
        list->last = s;
    }else{ 
    s->next = list->first->next;
    s->next->prio = s;
    }
    s->prio = list->first;
    list->first->next = s;
    list->size++;
};
void pop_front(List *list){
    if(list->size==0)
    return;
    Node *p = list->first->next;
    if(list->first->next==list->last){
         list->last = list->first;
         list->last->next==NULL;
    }else{
    p->next->prio = list->first;
    list->first->next = p->next;
    }
    free(p);
    list->size--;
    
    
};
void pop_back(List *list){
    if(list->size==0)
    return;
    Node *p = list->first;
    while (p->next!=list->last)
        p=p->next;
    free(list->last);
    list->last = p;
    p->next = NULL;
    list->size--;

};
void insert_val(List *list,ElemType x){
    Node *p = list->first;
    while (p->next!=NULL&&p->next->data<x)
    {
        p=p->next;
    }
    if(p->next ==list->last&& p->next->data<x){
        push_back(list,x);
    }
    else{
        Node *s = _buynode(x);
        s->next = p->next;
        s->next->prio =s;
        s->prio = p;
        p->next =s;
        list->size++;
    }
    

};
Node* find(List *list,ElemType key){
    Node *p = list->first->next;
    while (p!=NULL&&p->data!=key)
    {
        p=p->next;
    }
    return p;

};
int length(List *list){
    return list->size;
};
void delete_val(List *list,ElemType key){
      if(list->size == 0){
        return;
      }
      Node *p = find(list,key);
      if(p==NULL){
        printf("要删除的数据不存在\n");
      }
      if(p == list->last){
        pop_back(list);
      }else{
        p->next->prio=p->prio;
        p->prio->next = p->next;
        free(p);
        list->size--;

      }

};
void sort(List *list){
    if(list->size == 0 || list->size ==1)
    return;
    Node *s = list->first->next;
    Node *q = s->next;
    list->last->next = NULL;
    list->last =s ;
    list->last->next = list->first;
    list->first->prio = list->last;// 拆分链表
    while (q!=NULL)
    {
     s =q;   
     q = q->next;
     Node *p = list->first;
     while (p->next != list->last && p->next->data <s->data)
     {
         p = p->next;
     }
     if (p->next==list->last&&p->next->data<s->data)
     {
        s->next = list->last->next;
        s->next->prio = s;
        s->prio = list->last;
        list->last->next =s;
        list->last =s;
     }
     else
     {
         s->next = p->next;
         s->next->prio = s;
         s->prio = p;
         p->next = s;
     }
    }
};
void resver(List *list){
 if(list->size == 0 || list->size ==1)
    return;
    Node *p = list->first->next;
    Node *q = p->next;
    list->last->next = NULL;
    list->last =p ;
    list->last->next = list->first;
    list->first->prio = list->last;
    while (q!=NULL)
    {
        p =q ;
        q = q->next;
        p->next = list->first->next;
        p->next->prio = p;
        p->prio = list->first;
        list->first->next = p;
        list->last->next = NULL;
    }
    

};
void clear(List *list){
    if(list->size == 0){
        return;
    }
    Node *p = list->first->next;
    while (p!=list->first)
    {
        p->next->prio = list->first;
        list->first->next = p->next;
        free(p);
        p = list->first->next;
    }
    
};
void destroy(List *list){};
void show_list(List *list){
    Node *p = list->first->next;
    while (p!=NULL)
    {
        printf("%d-->",p->data);
        p= p->next;
    }
    printf("NULL\n");
    

};