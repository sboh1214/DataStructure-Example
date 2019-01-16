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
    int *ptr = (int *)calloc(length, sizeof(int));
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->TopPtr = ptr - 1;
    stack->BottomPtr = ptr;
    stack->EndPtr = ptr + length - 1;
    return stack;
}

void Stack_Push(Stack *stack, int value)
{
    if (stack->TopPtr + 1 == stack->EndPtr)
    {
        int length = stack->EndPtr - stack->BottomPtr + 1 + DEFAULT_EXPAND_SIZE;
        int *ptr = (int*)realloc(stack->BottomPtr, length * sizeof(int));
        stack->TopPtr = ptr + length - 1;
        stack->BottomPtr = ptr;
        stack->EndPtr = ptr + length - 1;
    }
    stack->TopPtr++;
    *(stack->TopPtr) = value;
}

int Stack_Peek(Stack *stack)
{
    if (stack->TopPtr == stack->BottomPtr - 1)
    {
        return ERROR;
    }
    else
    {
        return *(stack->TopPtr);
    }
}

int Stack_Pop(Stack *stack)
{
    if (stack->TopPtr == stack->BottomPtr - 1)
    {
        return ERROR;
    }
    if (stack->TopPtr + DEFAULT_SHRINK_SIZE < stack->EndPtr)
    {
        int length = stack->EndPtr - stack->BottomPtr + 1 - DEFAULT_SHRINK_SIZE;
        int *ptr = (int*)realloc(stack->BottomPtr, length * sizeof(int));
        stack->TopPtr = ptr + length - 1;
        stack->BottomPtr = ptr;
        stack->EndPtr = ptr + length - 1;
    }
    int value = *(stack->TopPtr);
    stack->TopPtr--;
    return value;
}

int Stack_IsEmpty(Stack *stack)
{
    if (stack->TopPtr == stack->BottomPtr - 1)
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