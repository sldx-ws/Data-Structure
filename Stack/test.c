#include "Stack.h"

void test()
{
    Stack stack;
    StackInit(&stack);
   
    printf("入栈："); 
    StackPush(&stack, 1);
    StackPush(&stack, 2);
    StackPush(&stack, 3);
    StackPush(&stack, 4);
    StackPush(&stack, 5);
    Print(&stack);

    printf("出栈：");
    StackPop(&stack);
    Print(&stack);

    printf("栈顶元素：");
    printf("%d\n", StackTop(&stack));

    printf("栈的大小；");
    printf("%zd\n", StackSize(&stack));
    
    StackDestroy(&stack);

}


int main()
{
    test();

    return 0;
}
