#include "SeqList.h"

// 测试头插头删
void TestSeqListPushPop()
{
    SeqList s;
    SeqListInit(&s);

    printf("尾插: ");
    SeqListPushBack(&s, 1);
    SeqListPushBack(&s, 2);
    SeqListPushBack(&s, 3);
    SeqListPushBack(&s, 4);
    SeqListPushBack(&s, 5);
    Print(&s);

    printf("尾删: ");
    SeqListPopBack(&s);
    SeqListPopBack(&s);
    Print(&s);
    
    printf("头插: ");
    SeqListPushFront(&s, -1);
    SeqListPushFront(&s, -2);
    Print(&s);

    printf("头删: ");
    SeqListPopFront(&s);
    SeqListPopFront(&s);
    Print(&s);

    printf("下标为2的位置插入10: ");
    SeqListInsert(&s, 2, 10);
    Print(&s);

    printf("删除下标为3元素: ");
    SeqListErase(&s, 3);
    Print(&s);

    printf("元素10的下标: %d\n", SeqListFind(&s, 10));

    SeqListDestroy(&s);
}

int main()
{
    TestSeqListPushPop();

    return 0;
}
