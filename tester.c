#include<stdio.h>

int test();

int main(int argc, char const *argv[])
{
    printf("%d", test());
}

int test()
{
    for(int i = 0; i < 20; i++)
    {
        if(i == 5)
            return 3;
    }
    return 10;
}