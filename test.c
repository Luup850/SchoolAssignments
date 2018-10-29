#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    for(int i = 10; i < 1000; i++)
    {
        malloc(99999999);
    }

    return 0;
}