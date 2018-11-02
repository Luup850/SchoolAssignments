#include<stdio.h>
#include<ctype.h>
#include<string.h>

/*  Prototype   */
void requestInfo(const char *ID, char*, char*, char*, int);

int main(void)
{
    char MMOC[] = {'A', 'T', 'L', '1', '2', '0', '3', 'S', '1', '4'};
    int size = sizeof(MMOC);
    char Warehouse[10], Product[10], Qualifiers[10];

    requestInfo(MMOC, Warehouse, Product, Qualifiers, size);

    printf("Warehouse: %s \nProduct: %s \nQualifiers: %s\n", Warehouse, Product, Qualifiers);

    return 0;
}

/* Request information about the ID */
void requestInfo(const char *ID, char *W, char *P, char *Q, int size)
{
    /* Loop through the array */
    for(int i = 0; i <= size; i++)
    {
        /* Check if current char is digit */
        if(isdigit(ID[i]))
        {
            /* Copy everything from the start to the first digit */
            strncpy(W, ID, i);
            /* Replace the digit with '\0' */
            W[i] = '\0';
            ID += i;
            i = size + 1;
        }
    }

    /* do the same as before, now looking for letters */
    for(int i = 0; i <= size; i++)
    {
        if(!isdigit(ID[i]))
        {
            strncpy(P, ID, i);
            P[i] = '\0';
            ID += i;
            i = size + 1;
        }
    }

    /* Copy the last bit of the ID and store it in Q */
    strcpy(Q, ID);
}
