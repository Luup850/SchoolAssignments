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

/* Main function */
int main(int argc, char const *argv[])
{
    cycleRace raceList[ARRAY_SIZE];

    loadDataSet(INPUT_FILE, raceList);

    printf("There should be stuff here! %s \n", raceList[1].raceName);

    return 0;
}

/* Load data into the raceList array */
void loadDataSet(const char *dataSet, cycleRace *r)
{
    /* Char array used to find name, lastname and placement */
    char a[MAX_NAME_SIZE];

    /* Open the data set */
    FILE* f;
    f = fopen(dataSet, "r");
    int ch = getc(f);
    int i = 0;

    do
    {
        fscanf(f, " %s", r[i].raceName); /* Race */
        //printf("%s\n", r[i].raceName);
        fscanf(f, " \" %[^\"]s", a); /* Racer name and lastname */
        
        /* Look for the first uppercase word */
        for(int j = 0; j <= MAX_NAME_SIZE; j++)
        {
            /* Check if the first letter is uppercase */
            if(isupper(a[j]))
            {
                /* Check if the second letter is uppercase, to find out where the last name begins */
                if(isupper(a[j+1]))
                {
                    /* Copy the first bit before the first uppercase word, since it gotta be the first name(s) */
                    strncpy(r[i].firstName, a, j-1);
                    //printf("%s ", r[i].firstName);

                    /* Copy the last bit since it gotta be the last name(s) */
                    strcpy(r[i].lastName, a+j);
                    //printf("%s\n", r[i].lastName);

                    /* Get out of for loop */
                    j = MAX_NAME_SIZE+1;
                }
            }
        }

        fscanf(f, " \" %*[|] %d", &r[i].age);
        //printf("%d \n", r[i].age);

        fscanf(f, " %s", r[i].team); /* Racer team */
        //printf("%s \n", r[i].team);
        fscanf(f, " %s", r[i].nationality); /* Racer nationality */
        //printf("%s \n", r[i].nationality);
        fscanf(f, " %*[|] %s", a); /* Racer placement (-2 if DNF and -1 if OTL) */
        //printf("%s \n", a);

        if(strcmp(a, "DNF") == 0)
        {
            //printf("Very bad");
            r[i].placement = -2;
            r[i].trackTimeHours = 0;
            r[i].trackTimeMin = 0;
            r[i].trackTimeSec = 0;
            fscanf(f, " -");
        }
        else if(strcmp(a, "OTL") == 0)
        {
            //printf("Bad");
            r[i].placement = -1;

            fscanf(f, " %d", &r[i].trackTimeHours);
            fscanf(f, ":%d", &r[i].trackTimeMin);
            fscanf(f, ":%d", &r[i].trackTimeSec);
        }
        else
        {
            //printf("Do we get this far?");
            fscanf(f, " %d", &r[i].trackTimeHours);
            fscanf(f, ":%d", &r[i].trackTimeMin);
            fscanf(f, ":%d", &r[i].trackTimeSec);
        }
        printf("I fuck up at %d\n", i);
        //printf("%d:%d:%d\n", r[i].trackTimeHours, r[i].trackTimeMin, r[i].trackTimeSec);
        i++;
    } while(ch == EOF);
}