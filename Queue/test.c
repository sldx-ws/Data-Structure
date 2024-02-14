#include "Queue.h"

void test()
{
    Queue q;
    QueueInit(&q);

    printf("入队：");
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    QueuePush(&q, 4);
    QueuePush(&q, 5);
    Print(&q);

    printf("出队：");
    QueuePop(&q);
    Print(&q);

    printf("队头：%d\n", QueueFront(&q));
    printf("队尾：%d\n", QueueBack(&q));

    printf("队列是否为空：%s\n", QueueEmpty(&q) == 1 ? "是" : "否");
    printf("队列的大小：%zd\n", QueueSize(&q));

    QueueDestory(&q);
}


int main()
{
    test();

    return 0;
}
