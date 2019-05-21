#ifndef _Settings
#include "_Settings.h"
#endif
#define _Stack

typedef struct
{
    int *BottomPtr; //start of allocated memory
    int *TopPtr;    //end of data
    int *EndPtr;    //end of allocated memory
    int Length;     //length of allocated memory
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
    stack->Length = length;
    return stack;
}

void Stack_Push(Stack *stack, int value)
{
    if (stack->TopPtr == stack->EndPtr) //Check whether stack is full or not
    {
        int length = stack->Length + EXPAND_SIZE;
        int *beforeBottomPtr = stack->BottomPtr;
        int *afterBottomPtr = (int *)realloc(stack->BottomPtr, length * sizeof(int));
        stack->EndPtr += EXPAND_SIZE;
        if (beforeBottomPtr != afterBottomPtr) //reallocated in different space
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
        int length = stack->Length - SHRINK_SIZE;
        (int *)realloc(stack->BottomPtr, length * sizeof(int));
        stack->EndPtr -= SHRINK_SIZE;
    }
    int value = *(stack->TopPtr);
    stack->TopPtr--;
    return value;
}

int Stack_IsEmpty(Stack *stack)
{
    if (stack->BottomPtr == stack->TopPtr-1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int Stack_Count(Stack *stack)
{
    return (int)(stack->TopPtr - stack->BottomPtr) + 1;
}

void Stack_Clear(Stack *stack)
{
    int length = INIT_SIZE;
    int *ptr = (int *)calloc(length, sizeof(int));
    stack->TopPtr = ptr - 1;
    stack->BottomPtr = ptr;
    stack->EndPtr = ptr + length - 1;
    stack->Length = length;
}

void Stack_Delete(Stack *stack)
{
    free(stack->BottomPtr);
    free(stack);
}