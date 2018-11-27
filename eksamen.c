#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h> /* Isupper */

/* Anti magic number system */
#define MAX_NAME_SIZE 40
#define MAX_TEAM_NATIONALITY_NAME 4
#define ARRAY_SIZE 790
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
void printNationalResults(const cycleRace *r, const char nat[4], const int overAge);


/* Main function */
int main(int argc, char const *argv[])
{
    cycleRace raceList[ARRAY_SIZE];
    cyclist riderList[ARRAY_SIZE];
    loadDataSet(INPUT_FILE, raceList);

    printNationalResults(raceList, "ITA", 30);

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
    int ch;
    int i = 0;

    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        //printf("I fuck up at %d\n", i);
        int s = fscanf(f, " %s", r[i].raceName); /* Race */
        //printf("%s\n", r[i].raceName);
        fscanf(f, " \" %[^\"]s", temp); /* Racer name and lastname */
        
        /* Look for the first uppercase word */
        for(int j = 0; j <= MAX_NAME_SIZE; j++)
        {
            /* Check if the first letter is uppercase */
            if(isupper(temp[j]) || temp[j] == '\'')
            {
                /* Check if the second letter is uppercase, to find out where the last name begins */
                if(isupper(temp[j+1]) || temp[j+1] == '\'')
                {
                    /* Copy the first bit before the first uppercase word, since it gotta be the first name(s) */
                    strncpy(r[i].firstName, temp, j-1);
                    r[i].firstName[j-1] = '\0';

                    /* Copy the last bit since it gotta be the last name(s) */
                    strcpy(r[i].lastName, temp+j);

                    /* Get out of for loop */
                    j = MAX_NAME_SIZE+1;
                }
            }
        }

        fscanf(f, " \" %*[|] %d", &r[i].age);

        fscanf(f, " %s", r[i].team); /* Racer team */

        fscanf(f, " %s", r[i].nationality); /* Racer nationality */

        fscanf(f, " %*[|] %s", temp); /* Racer placement (-2 if DNF and -1 if OTL) */
        if(strcmp(temp, "DNF") == 0)
        {
            r[i].placement = -2;
            r[i].trackTimeHours = 0;
            r[i].trackTimeMin = 0;
            r[i].trackTimeSec = 0;
            fscanf(f, " -");
        }
        else if(strcmp(temp, "OTL") == 0)
        {
            r[i].placement = -1;

            fscanf(f, " %d", &r[i].trackTimeHours);
            fscanf(f, ":%d", &r[i].trackTimeMin);
            fscanf(f, ":%d", &r[i].trackTimeSec);
        }
        else
        {
            r[i].placement = atoi(temp);
            fscanf(f, " %d", &r[i].trackTimeHours);
            fscanf(f, ":%d", &r[i].trackTimeMin);
            fscanf(f, ":%d", &r[i].trackTimeSec);
        }
    }

    fclose(f);
}

void printNationalResults(const cycleRace *r, const char nat[4], const int overAge)
{
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        if(strcmp(r[i].nationality, nat) == 0 && r[i].age >= overAge)
        {
            printf("%-20s\t| %-20s %-20s\t| %d\t| %s\t| %s\t| ", r[i].raceName, r[i].firstName, r[i].lastName, r[i].age, r[i].team, r[i].nationality);

            if(r[i].placement == -1)
                printf("OTL\t| ");
            else if(r[i].placement == -2)
                printf("DNF\t| ");
            else
                printf("%d\t| ", r[i].placement);

            printf("%d:%d:%d \n", r[i].trackTimeHours, r[i].trackTimeMin, r[i].trackTimeSec);
        }
    }
}