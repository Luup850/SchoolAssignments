#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Anti magic number system */
#define MAX_NAME_SIZE 40
#define MAX_TEAM_NATIONALITY_NAME 4
#define ARRAY_SIZE 790
#define INPUT_FILE "cykelloeb.txt"

/* Structs */
struct cycleRace
{
    char raceName[MAX_NAME_SIZE];
    char name[MAX_NAME_SIZE];
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
    char name[MAX_NAME_SIZE];
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
    cycleRace raceList[ARRAY_SIZE];

    loadDataSet(INPUT_FILE, raceList);

    printf("%s \n", raceList[0].name);

    return 0;
}

/* Load data into the raceList array */
void loadDataSet(const char *dataSet, cycleRace *r)
{
    /* Char array used to find name, lastname and placement */
    char a[MAX_NAME_SIZE];

    FILE* f;
    f = fopen(dataSet, "r");

    for(int i = 0; i <= 0; i++)
    {
        fscanf(f, " %s", r[i].raceName); /* Race */
        printf("%s\n", r[i].raceName);
        fscanf(f, " \" %[^\"]s", a); /* Racer name and lastname */
        printf("%s\n", a);
        /*for(int i = 0; i <= MAX_NAME_SIZE; i++)
        {

        }*/

        fscanf(f, " \" %*[|] %d", &r[i].age);
        printf("%d \n", r[i].age);

        fscanf(f, " %s", r[i].team); /* Racer team */
        printf("%s \n", r[i].team);
        fscanf(f, " %s", r[i].nationality); /* Racer nationality */
        printf("%s \n", r[i].nationality);
        fscanf(f, " %*[|] %s", a); /* Racer placement (-2 if DNF and -1 if OTL) */
        printf("%s \n", a);

        if(strcmp(a, "DNF") == 0)
        {
            printf("Very bad");
            r[i].placement = -2;
            r[i].trackTimeHours = 0;
            r[i].trackTimeMin = 0;
            r[i].trackTimeSec = 0;
            fscanf(f, " %*[-] ");
        }
        else if(strcmp(a, "OTL") == 0)
        {
            printf("Bad");
            r[i].placement = -1;

            fscanf(f, " %d", &r[i].trackTimeHours);
            fscanf(f, "%[:]s %d", &r[i].trackTimeMin);
            fscanf(f, "%[:]s %d ", &r[i].trackTimeSec);
        }
        else
        {
            printf("Do we get this far?");
            fscanf(f, " %d", &r[i].trackTimeHours);
            fscanf(f, ":%d", &r[i].trackTimeHours);
            fscanf(f, ":%d ", &r[i].trackTimeHours);
        }
        printf("%d:%d:%d\n", r[i].trackTimeHours, r[i].trackTimeMin, r[i].trackTimeSec);
    }
}