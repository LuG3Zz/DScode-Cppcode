#include "SeqList.cpp"


int main(int argc, char const *argv[])
{
    SeqList mylist;
    InitSeqList(&mylist);
    ElemType Item;
    int pos;
    int select =1 ;
    while (select)
    {
        printf("**************************************\n");
        printf("*    [1] push_back  [2] push_front   *\n");
        printf("*    [3] show_list  [4] pop_back     *\n");
        printf("*    [5] pop_front  [6] insert_pos   *\n");
        printf("*    [7] find       [8] length       *\n");
        printf("*    [9] delete_pos [10] delete_val  *\n");
        printf("*    [11] sort      [12] reverse     *\n");
        printf("*    [13] clear     [14] destroy     *\n");
        printf("*    [0 ] QUIT                       *\n");
        printf("**************************************\n");
        printf("请选择:>");
        scanf("%d",&select);
    if (select==0)
    {
        break;
    }
    switch (select)
    {
    case 1:
    printf("请输入要插入的数据:(以-1结束)");
    while (scanf("%d",&Item),Item!=-1)
    {
        push_back(&mylist,Item);
    }
    
    
        break;
    case 2:
    printf("请输入要插入的数据:(以-1结束)");
    while (scanf("%d",&Item),Item!=-1)
    {
        push_front(&mylist,Item);
    }
        break;
    case 3:
    show_list(&mylist);
        break;
    case 4:
    pop_back(&mylist);
        break;
    case 5:
    pop_front(&mylist);
        break;
    case 6:
    printf("请输入要插入的数据:>");
    scanf("%d",&Item);
    printf("请输入要插入的位置:>");
    scanf("%d",&pos);
    insert_pos(&mylist,pos,Item);
        break;
    case 7:
    printf("请输入要查找的数据:>");
    scanf("%d",&Item);
    pos = find(&mylist,Item);
    if(pos == -1){
    printf("查找的数据%d不存在\n",Item);
    }else{
    printf("查找的数据%d在顺序表中的位置：%d\n",Item,pos);
    }
        break;
    case 8:
    printf("顺序表的长度为：%d \n",length(&mylist));
        break;
    case 9:
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        break;
    case 13:
        break;
    case 14:
        break;
    default:
        printf("输入的选择错误，请重新输入");
        break;
    }
    }
    
    
}
