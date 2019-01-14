#ifndef Settings
#include "_Settings.h"
#endif

typedef struct
{
    int *BottomPtr;
    int *TopPtr;
    int *EndPtr;
} Stack;

Stack *Stack_Init(int length)
{
    if (length == 0)
    {
        length = DEFAULT_INIT_SIZE;
    }
    int *intPtr = (int *)calloc(length, sizeof(int));
    Stack *stackPtr = (Stack *)malloc(sizeof(Stack));
    stackPtr->TopPtr = intPtr - 1;
    stackPtr->BottomPtr = intPtr;
    stackPtr->EndPtr = intPtr + length - 1;
    return stackPtr;
}

int Stack_Peek(Stack *stackPtr)
{
    if (stackPtr->TopPtr == stackPtr->BottomPtr - 1)
    {
        return ERROR;
    }
    else
    {
        return *(stackPtr->TopPtr);
    }
}

int Stack_Pop(Stack *stackPtr)
{
    if (stackPtr->TopPtr == stackPtr->BottomPtr - 1)
    {
        return ERROR;
    }
    else
    {
        int value = *(stackPtr->TopPtr);
        stackPtr->TopPtr--;
        return value;
    }
}

void Stack_Push(Stack *stackPtr, int value)
{
    stackPtr->TopPtr++;
    *(stackPtr->TopPtr) = value;
}

int Stack_IsEmpty(Stack *stackPtr)
{
    if (stackPtr->TopPtr == stackPtr->BottomPtr - 1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void Stack_Delete(Stack *stack)
{
    free(stack->BottomPtr);
    free(stack);
}