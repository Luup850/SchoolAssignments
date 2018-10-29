#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define MAX_ARRAY_LENGHT 100
void genRandArray(double *, int);
int cmpfunc(const void*, const void*);
void printArray(double*, int);

int main(void)
{
    double *a;
    a = malloc(sizeof(double) * MAX_ARRAY_LENGHT);

    genRandArray(a, MAX_ARRAY_LENGHT);

    //printArray(a, MAX_ARRAY_LENGHT);

    qsort(a, MAX_ARRAY_LENGHT, sizeof(double), cmpfunc);

    printf("-------------------\n");
    printArray(a, MAX_ARRAY_LENGHT);
    
    free(a);

    return 0;
}

void genRandArray(double *p, int length)
{
    srand(time(NULL));

    for(int i = 0; i < length; i++)
    {
        p[i] = rand() / 2.00;
    }
}

int cmpfunc(const void *a, const void *b)
{
    int res;

    if(*(double*)a < *(double*)b)
    {
        res = -1;
    }
    else if(*(double*)a > *(double*)b)
    {
        res = 1;
    }
    else
    {
        res = 0;
    }

    return res;
}

void printArray(double *p, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("[%d]    %.2lf\n", i, p[i]);
    }
}