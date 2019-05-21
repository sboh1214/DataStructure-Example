#ifndef _Settings
#include "_Settings.h"
#endif
#define _Queue

typedef struct
{
    int *RearPtr;  //Put data, start of allocated memory
    int *FrontPtr; //Get Data
    int *EndPtr;   //Current end of allocated memory
    int Length;    //Length of allocated memory
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
    queue->Length = length;
    return queue;
}

void Queue_Put(Queue *queue, int value)
{
    if (queue->FrontPtr + 1 == queue->EndPtr) //Check whether queue is full or not
    {
        int length = queue->Length + EXPAND_SIZE;
        int *beforeRearPtr = queue->RearPtr;
        int *afterRearPtr = (int *)realloc(queue->RearPtr, length * sizeof(int)); //Expand Size of Queue
        queue->EndPtr += EXPAND_SIZE;
        if (beforeRearPtr != afterRearPtr)
        {
            int diffPtr = (int)(afterRearPtr - beforeRearPtr);
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
    if (queue->FrontPtr == queue->RearPtr - 1)
    {
        return ERROR;
    }
    if (queue->FrontPtr + SHRINK_SIZE < queue->EndPtr)
    {
        int length = queue->Length - SHRINK_SIZE;
        (int *)realloc(queue->RearPtr, length * sizeof(int));
        queue->EndPtr -= SHRINK_SIZE;
    }
    int value = *(queue->FrontPtr);
    queue->FrontPtr--;
    return value;
}

int Queue_IsEmpty(Queue * queue)
{
    if (queue->RearPtr == queue->FrontPtr-1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    
}

int Queue_Count(Queue * queue)
{
    return (int)(queue->FrontPtr-queue->RearPtr)+1;
}

void Queue_Clear(Queue * queue)
{
    int length = INIT_SIZE;
    int *ptr = (int *)calloc(length, sizeof(int));
    queue->RearPtr = ptr;
    queue->FrontPtr = ptr - 1;
    queue->EndPtr = ptr + length - 1;
    queue->Length = length;
}

void Queue_Delete(Queue *queue)
{
    free(queue->RearPtr);
    free(queue);
}