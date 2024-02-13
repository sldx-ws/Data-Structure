#include "List.h" 

void test()
{
    ListNode* head = ListInit2();

    ListPushBack(head, 1);
    ListPushBack(head, 2);
    ListPushBack(head, 3);
    ListPushBack(head, 4);
    ListPrint(head);
}

int main()
{
    test();

    return 0;
}
