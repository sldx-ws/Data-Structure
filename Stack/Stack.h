#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int STDataType;

typedef struct Stack
{
    STDataType* _a;
    int _top;
    int _capacity;
} Stack;

// 初始化和销毁
void StackInit(Stack* pst);
void StackDestroy(Stack* pst);

// 出栈入栈
void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);

// 取栈顶元素
STDataType StackTop(Stack* pst);

// 返回栈的大小
size_t StackSize(Stack* pst);

// 判断是否为空栈
int StackEmpty(Stack* pst);

void Print(Stack* pst);
