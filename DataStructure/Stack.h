#ifndef Settings
#include "_Settings.h"
#endif

typedef struct
{
    int *BottomPtr; //start of allocated memory
    int *TopPtr;    //end of data
    int *EndPtr;    //end of allocated memory
} Stack;

Stack *Stack_Init(int length)
{
    if (length == 0)
    {
        length = INIT_SIZE;
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
    if (stack->TopPtr == stack->EndPtr) //Check whether stack is full or not
    {
        int length = stack->EndPtr - stack->BottomPtr + 1 + EXPAND_SIZE;
        int *beforeBottomPtr = stack->BottomPtr;
        int *afterBottomPtr = (int *)realloc(stack->BottomPtr, length * sizeof(int));
        stack->EndPtr += EXPAND_SIZE;
        if (beforeBottomPtr !=  afterBottomPtr) //reallocated in different space
        {
            int diffPtr = (int)(afterBottomPtr - beforeBottomPtr);
            stack->BottomPtr += diffPtr;
            stack->TopPtr += diffPtr;
            stack->EndPtr += diffPtr;
        }
        
    }
    stack->TopPtr++;
    *(stack->TopPtr) = value; //push data at the top
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
    if (stack->TopPtr + SHRINK_SIZE < stack->EndPtr)
    {
        int length = stack->EndPtr - stack->BottomPtr + 1 - SHRINK_SIZE;
        (int *)realloc(stack->BottomPtr, length * sizeof(int));
        stack->EndPtr -= SHRINK_SIZE;
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