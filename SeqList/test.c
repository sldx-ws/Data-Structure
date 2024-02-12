#include "SeqList.h"

// 测试头插头删
void TestSeqListPushPop()
{
    SeqList s;
    SeqListInit(&s);
    SeqListPushBack(&s, 1);
    SeqListPushBack(&s, 2);
    SeqListPushBack(&s, 3);
    SeqListPushBack(&s, 4);
    SeqListPushBack(&s, 5);
    Print(&s);

    SeqListPopBack(&s);
    SeqListPopBack(&s);
    Print(&s);
    
    SeqListPushFront(&s, -1);
    SeqListPushFront(&s, -2);
    Print(&s);

    SeqListPopFront(&s);
    SeqListPopFront(&s);
    Print(&s);
}

int main()
{
    TestSeqListPushPop();

    return 0;
}
