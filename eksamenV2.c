#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h> /* Isupper */

/* Anti magic number system */
#define MAX_NAME_SIZE 40
#define MAX_TEAM_NATIONALITY_NAME 4
#define MAX_ARRAY_SIZE 124
#define DATA_SIZE 8000
#define INPUT_FILE "cykelloeb.text"

/* Structs */
struct cycleRace
{
    char raceName[MAX_NAME_SIZE];
    char firstName[MAX_NAME_SIZE];
    char lastName[MAX_NAME_SIZE];
    int age;
    char team[MAX_TEAM_NATIONALITY_NAME];
    char nationality[MAX_TEAM_NATIONALITY_NAME];
    int placement;
    int trackTimeHours;
    int trackTimeMin;
    int trackTimeSec;
};

struct cyclist
{
    char firstName[MAX_NAME_SIZE];
    char lastName[MAX_NAME_SIZE];
    int age;
};


/* Type defines */
typedef struct cycleRace cycleRace;
typedef struct cyclist cyclist;


/* Prototypes */
void loadDataSet(const char *dataSet, cycleRace *r);

/* Main function */
int main(int argc, char const *argv[])
{
    cycleRace raceList[DATA_SIZE];
    loadDataSet(INPUT_FILE, raceList);
    //printf("There should be stuff here! %s \n", raceList[3].raceName);

    return 0;
}

/* Load data into the raceList array */
void loadDataSet(const char *dataSet, cycleRace *r)
{
    /* Char array used to find name, lastname and placement */
    char temp[MAX_NAME_SIZE];

    /* Open the data set */
    FILE* f;
    f = fopen(dataSet, "r");

    char data[MAX_ARRAY_SIZE];
    int i = 0;

    while(fgets(data, MAX_ARRAY_SIZE, f) != NULL)
    {
        sscanf(data, "%s", &(r[i].raceName));
        printf("There should be stuff here! %s \n", r[i].raceName);
        i++;
    }

    fclose(f);
}