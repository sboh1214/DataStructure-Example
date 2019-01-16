#include <stdio.h>
#include <time.h>

#include "DataStructure/_DataStructure.h"

int main()
{
    printf("Stack\n");
    Stack *stack = Stack_Init(100);
    Stack_Push(stack, 10);
    Stack_Push(stack, 20);
    Stack_Push(stack, 30);
    printf("10 20 30\n");
    printf("%d ", Stack_Pop(stack));
    printf("%d ", Stack_Pop(stack));
    printf("%d ", Stack_Pop(stack));
    Stack_Delete(stack);
    printf("\n");

    printf("Queue\n");
    Queue *queue = Queue_Init(0);
    Queue_Put(queue, 10);
    Queue_Put(queue, 20);
    Queue_Put(queue, 30);
    printf("10 20 30\n");
    printf("%d ", Queue_Get(queue));
    printf("%d ", Queue_Get(queue));
    printf("%d ", Queue_Get(queue));
    Queue_Delete(queue);
    printf("\n");

    return 0;
}
