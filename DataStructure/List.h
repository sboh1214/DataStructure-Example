#ifndef _Settings
#include "_Settings.h"
#endif
#define _List

typedef struct
{
    int* HeadPtr; //start of list, start of allocated memory
    int* TailPtr; //end of list
    int* EndPtr;  //end of allocated memory
    int Length;   //length of allocated memory
}List;

List* List_Init(int length)
{
    if (length == 0)
    {
        length = INIT_SIZE;
    }
    int *ptr = (int *)calloc(length, sizeof(int));
    List *list = (List *)malloc(sizeof(List));
    list->HeadPtr = ptr;
    list->TailPtr = ptr - 1;
    list->EndPtr = ptr + length - 1;
    list->Length = length;
    return list;
}

void List_Add(List * list, int value)
{
    if (list->TailPtr == list->EndPtr) //Check whether list is full or not
    {
        int length = list->Length + EXPAND_SIZE;
        int *beforeBottomPtr = list->HeadPtr;
        int *afterBottomPtr = (int *)realloc(list->HeadPtr, length * sizeof(int));
        list->EndPtr += EXPAND_SIZE;
        if (beforeBottomPtr != afterBottomPtr) //reallocated in different space
        {
            int diffPtr = (int)(afterBottomPtr - beforeBottomPtr);
            list->HeadPtr += diffPtr;
            list->TailPtr += diffPtr;
            list->EndPtr += diffPtr;
        }
    }
    list->TailPtr++;
    *(list->TailPtr) = value; //Add data at tail
}

void List_InsertAt(List * list, int index, int value)
{
    if (list->TailPtr == list->EndPtr) //Check whether list is full or not
    {
        int length = list->Length + EXPAND_SIZE;
        int *beforeBottomPtr = list->HeadPtr;
        int *afterBottomPtr = (int *)realloc(list->HeadPtr, length * sizeof(int));
        list->EndPtr += EXPAND_SIZE;
        if (beforeBottomPtr != afterBottomPtr) //reallocated in different space
        {
            int diffPtr = (int)(afterBottomPtr - beforeBottomPtr);
            list->HeadPtr += diffPtr;
            list->TailPtr += diffPtr;
            list->EndPtr += diffPtr;
        }
    }

    //TODO
}

void List_RemoveAt(List * list, int index)
{

}

int List_Count(List * list)
{
    return (int)(list->TailPtr-list->HeadPtr)+1;
}

void List_Clear(List * list)
{

}

void List_Delete(List * list)
{
    free(list->HeadPtr);
    free(list);
}