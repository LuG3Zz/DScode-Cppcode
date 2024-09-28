#include "SeqStack.cpp"

// void Convert_8(int value){
//     SeqStack st;
//     InitStack(&st);
//     int v;
//     while (value)
//     {
//         Push(&st,value%8);
//         value/=8;
//     }
//     while (!IsEmpty(&st))
//     {
//         GetTop(&st,&v);
//         Pop(&st);
//         printf("%d",v);
//     }
// }
void LineEdit(){
    SeqStack st;
    InitStack(&st);
    char ch = getchar();
    while (ch!='$')
    {
        while (ch!='$' && ch!='\n')
        {
            switch (ch)
            {
            case '#':
                Pop(&st);
                break;
            case '@':
                Clear(&st);
                break;
            
            default:
                Push(&st,ch);
                break;
            }
            ch = getchar();
        }
        Print(&st);
    ch=getchar();
    }
   Destroy(&st); 
}
bool Check(char *s ){
    SeqStack st;
    InitStack(&st);
    char v;
    while (*s =='\0'){
        if(*s == '['|| *s =='('){
            Push(&st,*s);

        }else if(*s=']'||*s ==')'){
            GetTop(&st,&v);
            if(v!='[')
                return false;
            Pop(&st);
        }else if(*s == ')'){
            GetTop(&st,&v);
            if(v!='(')
                return false;
            Pop(&st);
        }
        ++s;

    }
    return IsEmpty(&st);

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

    // Convert_8(47183);
    char *str = "[([][])]";
    if(Check(str)){
        printf("OK!\n");
    }else{
        printf("ERROR!\n");

    }
    LineEdit();
    

    return 0;
}
