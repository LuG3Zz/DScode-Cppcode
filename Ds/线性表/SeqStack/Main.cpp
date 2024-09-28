#include "SeqStack.cpp"

void Convert_8(int value){
    SeqStack st;
    InitStack(&st);
    while (value)
    {
        Push(&st,value%8);
        value/=8;
    }
    Show(&st);
    
    


}

int main(int argc, char const *argv[])
{
    // SeqStack st;
    // InitStack(&st);
    // ElemType v;
    // for (int i = 1; i <= 20; i++)
    // {
    //     Push(&st,i);
    // }
    // Show(&st);
    // GetTop(&st,&v);
    // printf("%d出栈\n",v);
    // Pop(&st);
    // Show(&st);

    Convert_8(47183);
    

    return 0;
}
