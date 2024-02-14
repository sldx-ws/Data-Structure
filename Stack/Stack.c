#include "Stack.h"

// 初始化和销毁
void StackInit(Stack* pst)
{
    assert(pst);

    pst->_a = (STDataType*)malloc(sizeof(STDataType));
    if (pst->_a == NULL)
    {
        printf("内存申请失败\n");
        exit(-1);
    }

    pst->_top = 0;
    pst->_capacity = 4;
}

void StackDestory(Stack* pst)
{
    assert(pst);

    free(pst->_a);
    pst->_a = NULL;
    pst->_top = 0;
    pst->_capacity = 0;
}

// 出栈入栈
void StackPush(Stack* pst, STDataType x)
{
    assert(pst);

    if (pst->_top >= pst->_capacity)
    {
        pst->_capacity *= 2;
        STDataType* tmp = (STDataType*)realloc(pst->_a, pst->_capacity);
        if (tmp == NULL)
        {
            printf("内存申请失败\n");
            exit(-1);
        }

        pst->_a = tmp; 
    }

    pst->_a[pst->_top] = x;
    ++pst->_top; 
}

void StackPop(Stack* pst)
{
    assert(pst);
    assert(pst->_top > 0);

    --pst->_top;
}

// 取栈顶元素
STDataType StackTop(Stack* pst)
{
    assert(pst);
    assert(pst->_top > 0);

    return pst->_a[pst->_top - 1];
    
}

// 返回栈的大小
size_t StackSize(Stack* pst)
{
    assert(pst);

    return pst->_top;
}

// 判断是否为空栈
int StackEmpty(Stack* pst)
{
    assert(pst);

    return !pst->_top;
}

void Print(Stack* pst)
{
    assert(pst);

    for (int i = 0; i < pst->_top; ++i)
    {
        printf("%d ", pst->_a[i]);
    }

    printf("\n");
}
