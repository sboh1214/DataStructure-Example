#include <stdio.h>
#include "Stack.h"

int main(int argc, char const *argv[])
{
    Stack * stack1;
    stack1 = Stack_Init();
    Stack_Push(stack1,140);
    printf("%d",Stack_Peek(stack1));
    return 0;
}
