#ifndef Settings
#include "_Settings.h"
#endif

typedef struct
{
    int *FrontPtr;
    int *RearPtr;
    int *EndPtr;
} Queue;

Queue *Queue_Init(int length)
{
    if (length == 0)
    {
        length = DEFAULT_INIT_SIZE;
    }
    int *intPtr = (int *)calloc(length, sizeof(int));
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->FrontPtr = intPtr - 1;
    queue->RearPtr = intPtr;
    queue->EndPtr = intPtr + length - 1;
    return queue;
}

void Queue_Put(Queue *queue, int value)
{
    if (queue->FrontPtr + 1 == queue->EndPtr)
    {
        int length = queue->EndPtr - queue->FrontPtr +1 + DEFAULT_EXPAND_SIZE;
        int* intPtr = (int*)realloc(queue->RearPtr, length * sizeof(int));
        queue->FrontPtr = intPtr - 1;
        queue->RearPtr = intPtr;
        queue->EndPtr = intPtr + length - 1;
    }
    for (int *tempPtr = queue->FrontPtr; tempPtr >= queue->RearPtr; tempPtr--)
    {
        *(tempPtr + 1) = *tempPtr;
    }
    *(queue->RearPtr) = value;
    queue->FrontPtr++;
}

int Queue_Get(Queue *queue)
{
    if(queue->FrontPtr+DEFAULT_SHRINK_SIZE < queue->EndPtr)
    {
        int length = queue->EndPtr - queue->FrontPtr+1 - DEFAULT_SHRINK_SIZE;
        int* intPtr = (int*)realloc(queue->RearPtr, length * sizeof(int));
        queue->FrontPtr = intPtr - 1;
        queue->RearPtr = intPtr;
        queue->EndPtr = intPtr + length - 1;
    }
    int value = *(queue->FrontPtr);
    queue->FrontPtr--;
    return value;
}

void Queue_Delete(Queue *queue)
{
    free(queue->RearPtr);
    free(queue);
}