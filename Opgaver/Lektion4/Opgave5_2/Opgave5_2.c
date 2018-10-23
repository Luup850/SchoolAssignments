#include<stdio.h>
#include"primes.h"

int main()
{
    int input, prime = 0, start = 0;

    printf("Input: ");
    scanf("%d", &input);

    do
    {
        if(is_prime(start) == 1)
        {
            printf("[%d] number %d is a prime number\n", prime, start);
            prime++;
        }
        start++;
    } while(prime <= input);

    return 0;
}
