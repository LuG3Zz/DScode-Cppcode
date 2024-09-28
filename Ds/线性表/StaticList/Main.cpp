#include "StaticList.cpp"


int main(int argc, char const *argv[])
{
    StaticList SL;
    InitSList(SL);
    for (int i = 0; i < 5; i++)
    {
        Insert(SL,'A'+i);
    }
    ShowSList(SL);
    
    return 0;
}
