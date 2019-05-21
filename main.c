#include <stdio.h>
#include "DataStructure/_DataStructure.h"

int main()
{
    printf("Stack\n");
    Stack *stack = Stack_Init(0);
    for (int i = 0; i < 15; i++)
    {
        Stack_Push(stack, i);
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < 15; i++)
    {
        printf("%d ", Stack_Pop(stack));
    }
    printf("\n");
    Stack_Delete(stack);

    printf("Queue\n");
    Queue *queue = Queue_Init(0);
    for (int i=0;i<5;i++)
    {
        Queue_Put(queue, i);
        printf("%d ",i);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", Queue_Get(queue));
    }
    printf("\n");
    Queue_Delete(queue);

    return 0;
}
