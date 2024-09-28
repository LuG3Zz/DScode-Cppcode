#include "SeqList.cpp"


int main(int argc, char const *argv[])
{
    SeqList mylist,yourlist,list;
    InitSeqList(&mylist);
    InitSeqList(&yourlist);

    push_back(&mylist,1);
    push_back(&mylist,3);
    push_back(&mylist,5);
    push_back(&mylist,7);
    push_back(&mylist,9);

    push_back(&yourlist,2);
    push_back(&yourlist,4);
    push_back(&yourlist,6);
    push_back(&yourlist,8);
    push_back(&yourlist,10);

    merge(&list,&mylist,&yourlist);
    show_list(&list);
    return 0;
}
