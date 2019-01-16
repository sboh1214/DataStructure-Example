#include <stdio.h>
#include "DataStructure/_DataStructure.h"

int main(int argc, char const *argv[])
{
    int i;

    Queue * queue = Queue_Init(0);
    for(i=0;i<1000000000;i++)
    {
        Queue_Put(queue,10);
    }
    Queue_Delete(queue);
    return 0;
}
