#include "List.h" 

void test()
{
    ListNode* head = ListInit2();

    printf("尾插：");
    ListPushBack(head, 1);
    ListPushBack(head, 2);
    ListPushBack(head, 3);
    ListPushBack(head, 4);
    ListPrint(head);

    printf("尾删：");
    ListPopBack(head);
    ListPrint(head);

    printf("头插：");
    ListPushFront(head, -1);
    ListPrint(head);

    printf("头删：");
    ListPopFront(head);
    ListPrint(head);

    printf("在3前面插入99：");
    ListNode* pos = ListFind(head, 3);
    ListInsert(pos, 99);
    ListPrint(head);

    printf("删除2：");
    pos = ListFind(head, 2);
    ListErase(pos);
    ListPrint(head);

    ListDestory(head);
}

int main()
{
    test();

    return 0;
}
