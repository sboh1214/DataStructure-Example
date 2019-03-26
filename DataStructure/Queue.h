#ifndef Settings
#include "_Settings.h"
#endif

typedef struct
{
    int *RearPtr;  //Put data, start of allocated memory
    int *FrontPtr; //Get Data
    int *EndPtr;   //Current end of allocated memory
} Queue;

Queue *Queue_Init(int length)
{
    if (length == 0)
    {
        length = INIT_SIZE;
    }
    int *ptr = (int *)calloc(length, sizeof(int));
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->RearPtr = ptr;
    queue->FrontPtr = ptr - 1;
    queue->EndPtr = ptr + length - 1;
    return queue;
}

void Queue_Put(Queue *queue, int value)
{
    if (queue->FrontPtr == queue->EndPtr) //Check whether queue is full or not
    {
        int length = queue->EndPtr - queue->FrontPtr + 1 + EXPAND_SIZE;
        int *beforeRearPtr = queue->RearPtr;
        int *afterRearPtr = (int *)realloc(queue->RearPtr, length * sizeof(int)); //Expand Size of Queue
        queue->EndPtr += EXPAND_SIZE;
        if (beforeRearPtr != afterRearPtr)
        {
            int diffPtr = (int)(afterRearPtr- beforeRearPtr);
            queue->RearPtr += diffPtr;
            queue->FrontPtr += diffPtr;
            queue->EndPtr += diffPtr;
        }
    }
    for (int *tempPtr = queue->FrontPtr; tempPtr >= queue->RearPtr; tempPtr--)
    {
        *(tempPtr + 1) = *tempPtr;
    }
    *(queue->RearPtr) = value; //Put Data at the Rear
    queue->FrontPtr++;
}

int Queue_Get(Queue *queue)
{
    if (queue->FrontPtr == queue->RearPtr -1)
    {
        return ERROR;
    }
    if (queue->FrontPtr + SHRINK_SIZE < queue->EndPtr)
    {
        int length = queue->EndPtr - queue->FrontPtr + 1 - SHRINK_SIZE;
        (int *)realloc(queue->RearPtr, length * sizeof(int));
        queue->EndPtr -= SHRINK_SIZE;
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