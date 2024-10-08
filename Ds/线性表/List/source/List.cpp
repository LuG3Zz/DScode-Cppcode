#include <stdio.h>
#include <assert.h>
#include <malloc.h>

#define ElemType int

typedef struct ListNode {
    ElemType data;
    struct ListNode *next;
} ListNode, *List;

void InitList(List *head) {
    *head = (ListNode*)malloc(sizeof(ListNode));
    assert(*head!=NULL);
    (*head)->next = NULL;
}
void CreateList(List *head){
    for (int i = 0; i < 10; i++)
    {
        ListNode *s = (ListNode*)malloc(sizeof(ListNode));
        s->data = i;
        s->next = (*head)->next;
        (*head)->next =s ;
    }
    
}


// void CreateList(List *head) {
//     *head = (ListNode *)malloc(sizeof(ListNode));
//     assert(*head != NULL);
//     (*head)->data = 1;
//     (*head)->next = NULL;

//     ListNode *p = *head;
//     for (int i = 2; i <= 10; i++) {
//         ListNode *s = (ListNode*)malloc(sizeof(ListNode));
//         assert(s != NULL);
//         s->data = i;
//         s->next = NULL;
//         p->next = s;
//         p = s;
//     }
// }

void ShowList(List head) {
    ListNode *p = head->next;
    while (p != NULL) {
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[]) {
    List mylist;
    InitList(&mylist);
    CreateList(&mylist);
    ShowList(mylist);

    return 0;
}
