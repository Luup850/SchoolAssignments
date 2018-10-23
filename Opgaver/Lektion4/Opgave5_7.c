#include<stdio.h>

int main() {

int input, sum = 0;
printf("Input number: ");
scanf("%d\n", &input );

    sumIter(sumFormula(input));

    printf("Done...\n");
    return 0;
}

int sumIter(int a)
{
    int sum = 0;
    int lastSum;
    for (int i = 1; i <= a; i++)
    {
        lastSum += 1;
        sum += lastSum;
    }
    return sum;
}

int sumFormula(int a)
{
    return (a * (a + 1)) / 2;
}