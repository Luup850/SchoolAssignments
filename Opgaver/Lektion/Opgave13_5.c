#include<stdio.h>

#define MAX_NAME_LGT 50

struct person
{
    char fornavn[MAX_NAME_LGT];
    char efternavn[MAX_NAME_LGT];
    char vejnavn[MAX_NAME_LGT];
    int vejnummer;
    int postnummer;
    char bynavn[MAX_NAME_LGT];
};

typedef struct person person;

void loadData(person*, FILE*);

int main(void)
{
    FILE* f;
    f = fopen("file.text", "r");
    person list[11];

    loadData(list, f);

    printf("%s ssss", list[1].fornavn);

    return 0;
}

void loadData(person* list, FILE* f)
{
    int i = 0;
    while(i < 11)
    {
        fscanf(f, "%s[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ] %s[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ], %s[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ] %d, %d %s[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890]. ", list[i].fornavn, list[i].efternavn, list[i].vejnavn, list[i].vejnummer, list[i].postnummer, list[i].bynavn);
            printf("%s \n", list[i].efternavn);
        i++;
    }
}