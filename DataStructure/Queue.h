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
    queue->FrontPtr = intPtr-1;
    queue->RearPtr = intPtr;
    queue->EndPtr = intPtr + length - 1;
    return queue;
}

Queue *Queue_Put(Queue *queue, int value)
{
    for (int * tempPtr = queue->FrontPtr; tempPtr>=queue->RearPtr; tempPtr--)
    {
        *(tempPtr+1) = *tempPtr;
    }
    *(queue->RearPtr) = value;
    queue->FrontPtr++;
}

int Queue_Get(Queue *queue)
{
    int value = *(queue->FrontPtr);
    queue->FrontPtr--;
    return value;
}

Queue *Queue_Delete(Queue *queue)
{
    free(queue->RearPtr);
    free(queue);
}