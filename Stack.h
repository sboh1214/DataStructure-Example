#include <stdlib.h>
#include "Constant.h"

typedef struct
{
    int *BottomPtr;
    int *TopPtr;
} Stack;

Stack *Stack_Init()
{
    int *intPtr = (int *)calloc(DEFAULT_INIT_SIZE, sizeof(int));
    Stack *stackPtr = (Stack *)malloc(sizeof(Stack));
    stackPtr->TopPtr = intPtr;
    stackPtr->BottomPtr = intPtr;
    return stackPtr;
}

int Stack_Peek(Stack *stackPtr)
{
    if (stackPtr->TopPtr == stackPtr->BottomPtr)
    {
        return ERROR;
    }
    else
    {
        return *(stackPtr->TopPtr-1);
    }
}

int Stack_Pop(Stack *stackPtr)
{
    if (stackPtr->TopPtr == stackPtr->BottomPtr)
    {
        return ERROR;
    }
    else
    {
        stackPtr->TopPtr--;
        return *(stackPtr->TopPtr);
    }
}

Stack *Stack_Push(Stack * stackPtr, int value)
{
    *(stackPtr->TopPtr) = value;
    stackPtr->TopPtr++;
}

int Stack_IsEmpty(Stack * stackPtr)
{
    if(stackPtr->TopPtr == stackPtr->BottomPtr)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
