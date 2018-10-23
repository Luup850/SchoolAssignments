#include<stdio.h>

//Prototypes
int getUserInput();
void convertToBills(int, int*, int*, int*, int*);


int main()
{
    int bill_10 = 0, bill_20 = 0, bill_50 = 0, bill_100 = 0;

    convertToBills(getUserInput(), &bill_10, &bill_20, &bill_50, &bill_100);

    printf("Printing out: ");

    printf(bill_10 > 0 ? "[%d] 10 dollar bills" : "", bill_10);
    printf(bill_20 > 0 && bill_10 > 0 ? ", " : "");

    printf(bill_20 > 0 ? "[%d] 20 dollar bills" : "", bill_20);
    printf(bill_50 > 0 && bill_20 > 0 ? ", " : "");

    printf(bill_50 > 0 ? "[%d] 50 dollar bills" : "", bill_50);
    printf(bill_100 > 0 && bill_50 > 0 ? ", " : "");

    printf(bill_100 > 0 ? "[%d] 100 dollar bills" : "", bill_100);

    printf("\n\n");
    return 0;
}

int getUserInput()
{
    int input = 10;
    
    do
    {
        if(input < 0 || (input % 10) != 0)
            printf("ERROR: Invalid input!\n");

        printf("Please enter the amount you want to withdraw: ");
        scanf(" %d", &input);

    } while(input < 0 || (input % 10) != 0);

    return input;
}

void convertToBills(int input, int *bill10, int *bill20, int *bill50, int *bill100)
{
    int rest = 0;

    *bill100    = input / 100;
    rest        = input % 100;

    *bill50     = rest / 50;
    rest        = rest % 50;

    *bill20     = rest / 20;
    rest        = rest % 20;

    *bill10     = rest / 10;
    rest        = rest % 10;
}