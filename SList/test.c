#include "SList.h"

void test()
{
    SListNode* SList = NULL;
    
    printf("尾插：");
    SListPushBack(&SList, 1);
    SListPushBack(&SList, 2);
    SListPushBack(&SList, 3);
    SListPushBack(&SList, 4);
    SListPrint(SList);

    printf("尾删：");
    SListPopBack(&SList);
    SListPrint(SList);

    printf("头插：");
    SListPushFront(&SList, -1);
    SListPushFront(&SList, -2);
    SListPushFront(&SList, -3);
    SListPrint(SList);

    printf("头删：");
    SListPopFront(&SList);
    SListPrint(SList);

    // 查找+修改
    printf("将1修改为20：");
    SListNode* pos = SListFind(SList, 1);
    if (pos)
    {
        pos->_data = 20;
    }
    SListPrint(SList);

    // 指定位置之后插入删除
    printf("在20后面插入30：");
    SListInsertAfter(pos, 30);
    SListPrint(SList);

    printf("删除30：");
    SListEraseAfter(pos);
    SListPrint(SList);
}

int main()
{
    test();

    return 0;
}
