#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h> /* Isupper */

/* Anti magic number system */
#define MAX_NAME_SIZE 40
#define MAX_TEAM_NATIONALITY_NAME 4
#define ARRAY_SIZE 790
#define INPUT_FILE "cykelloeb"

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
    char nationality[MAX_TEAM_NATIONALITY_NAME];
    int numberOfCompletedRaces;
    int points;
};


/* Type defines */
typedef struct cycleRace cycleRace;
typedef struct cyclist cyclist;


/* Prototypes */
void loadDataSet(const char *dataSet, cycleRace *r);
void printNationalResults(const cycleRace *r, const char nat[4], const int overAge, const int underAge);
int createUniqueList(const cycleRace *r, cyclist *p);
void loadStringOfRiders(const cyclist *p, const int listLength, const int minRaceComp, const char *nat, char *resToReturn);
int participants(const char *race, const cycleRace *r);
void calculateScore(cyclist *p, const cycleRace *r, const int listLength);
void sortByTop(cyclist *p, const int listLength);
int cmpfunc(const void *a, const void *b);


/* Main function */
int main(int argc, char const *argv[])
{
    /* Variables */
    cycleRace raceList[ARRAY_SIZE];
    cyclist riderList[ARRAY_SIZE];
    char listOfDanishRiders[ARRAY_SIZE];
    int menuVar = 0;
    /* ---------------------------------- */


    /* Initialization */
    loadDataSet(INPUT_FILE, raceList);
    int u = createUniqueList(raceList, riderList);
    loadStringOfRiders(riderList, u, 1, "DEN", listOfDanishRiders);
    calculateScore(riderList, raceList, u);
    sortByTop(riderList, u);
    /* ---------------------------------------------- */
    

    if(strcmp(argv[1], "--print") == 0)
    {
        menuVar = -1;

        /* Opgave 1 */
        printf("Opgave 1:\n");
        printNationalResults(raceList, "ITA", 30, 99);

        /* Opgave 2 */
        printf("\n\nOpgave 2:\n");
        printf("%s", listOfDanishRiders);

        /* Opgave 3 */
        printf("\n\nOpgave 3:\n");
        printf("--------------------------------------------\nPosition \t|  Name \t|  Points\n--------------------------------------------\n");
        for(int i = 0; i < 10; i++)
        {
            printf("Placement: %-4d %-20s %-20s %10d\n", i+1, riderList[i].firstName, riderList[i].lastName, riderList[i].points);
        }
    }


    while(menuVar != -1)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\nChoose which assignment you want to run (1-5) \nTo exit the program enter -1\n");
        scanf(" %d", &menuVar);
        if(menuVar == 1)
        {
            // Opgave 1
            printNationalResults(raceList, "ITA", 30, 99);
        }
        else if(menuVar == 2)
        {
            // Opgave 2
            printf("%s", listOfDanishRiders);
        }
        else if(menuVar == 3)
        {
            // Opgave 3
            for(int i = 0; i < 10; i++)
            {
                printf("Placement: %-4d %-20s %-20s\n", i, riderList[i].firstName, riderList[i].lastName);
            }
        }

        if(menuVar != -1)
        {
            printf("\nType 'r' to return to the menu\n");
            scanf(" r");
        }
    }

    // Opgave 2

    /*
    for(int i = 0; i < u; i++)
    {
        printf("%5d %s \n", riderList[i].numberOfCompletedRaces, riderList[i].firstName);
    }*/

    return 0;
}


/*--------------------------------------
    Load data into the raceList array 
--------------------------------------*/
void loadDataSet(const char *dataSet, cycleRace *r)
{
    /* Char array used to find name, lastname and placement */
    char temp[MAX_NAME_SIZE];

    /* Open the data set */
    FILE* f;
    f = fopen(dataSet, "r");

    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        //printf("I fuck up at %d\n", i);
        fscanf(f, " %s", r[i].raceName); /* Race */
        //printf("%s\n", r[i].raceName);
        fscanf(f, " \" %s", r[i].firstName);
        fscanf(f, " %[^\"]s", temp); /* Racer name and lastname */
        
        /* Look for the first uppercase word */
        for(int j = 0; j <= MAX_NAME_SIZE; j++)
        {
            /* Check if the first letter is uppercase */
            if(isupper(temp[j]) || temp[j] == '\'')
            {
                /* Check if the second letter is uppercase, to find out where the last name begins */
                if(isupper(temp[j+1]) || temp[j+1] == '\'')
                {
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


/*---------------------------------------------------------------------------------------------------
    1. Function that prints race results for a specific country where the rider has a specific age 
----------------------------------------------------------------------------------------------------*/
void printNationalResults(const cycleRace *r, const char nat[4], const int overAge, const int underAge)
{
    printf("-----------------------------------------------------------\n");
    printf("Race \tName \tAge \tTeam \tNationality\n");
    printf("-----------------------------------------------------------\n");
    /* Loop throgh all results */
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        /* Check the nationality and the age of the rider */
        if(strcmp(r[i].nationality, nat) == 0 && r[i].age >= overAge && r[i].age < underAge)
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


/*------------------------------------------------------------------------------
    Function that creates a list of the riders and how many races they've won
------------------------------------------------------------------------------*/
int createUniqueList(const cycleRace *r, cyclist *p)
{
    /* Var storing how many unique people there is */
    int uniquePerson = 0;

    /* Setting completed races to zero by default */
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        p[i].numberOfCompletedRaces = 0;
    }

    /* Loop through r */
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        /* Var used to check if the name has been found before */
        int nameFound = 0;

        /* Loop through p to see if we already have that rider */
        for(int j = 0; j < ARRAY_SIZE; j++)
        {
            /* If we have that rider. Set nameFound to 1 */
            if(strcmp(r[i].firstName, p[j].firstName) == 0 && strcmp(r[i].lastName, p[j].lastName) == 0)
            {
                nameFound = 1;

                if(r[i].placement > -2)
                {
                    p[j].numberOfCompletedRaces += 1;
                }
            }
        }

        /* if we didnt find name then we know its the first time we've found this rider. Create a new rider in p */
        if(!nameFound)
        {
            /* Copy the riders name, lastname and age from r to p */
            strcpy(p[uniquePerson].firstName, r[i].firstName);
            strcpy(p[i].lastName, r[i].lastName);
            p[i].age = r[i].age;
            strcpy(p[uniquePerson].nationality, r[i].nationality);

            /* Count up uniquePerson since this is the first time we've found this rider */
            uniquePerson++;

            /* If this unique rider didnt DNF then increase completed races to 1 */
            if(r[uniquePerson].placement > -2)
            {
                p[uniquePerson].numberOfCompletedRaces = 1;
            }
        }
    }
    /* Return how many unique people there is in the list */
    return uniquePerson;
}


/*
    2. Return a list of all riders with a specific nationality 
*/
void loadStringOfRiders(const cyclist *p, const int listLength, const int minRaceComp, const char *nat, char *resToReturn)
{
    char buffer[20];
    strcat(resToReturn, "------------------------\nNumber \tNames\n------------------------\n");

    for(int i = 0; i <= listLength; i++)
    {
        /* Check if the current rider matches with the specifications given */
        if(strcmp(p[i].nationality, nat) == 0 && p[i].numberOfCompletedRaces >= minRaceComp)
        {
            /* Great he did. Now copy everything into the string resToReturn */
            strcat(resToReturn, itoa(p[i].numberOfCompletedRaces, buffer, 10));
            strcat(resToReturn, "\t");
            strcat(resToReturn, p[i].firstName);
            strcat(resToReturn, " ");
            strcat(resToReturn, p[i].lastName);
            strcat(resToReturn, "\n");
        }
    }
}


/* Calculate number of participants in a race */
int participants(const char *race, const cycleRace *r)
{
    int result = 0;
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        if(strcmp(r[i].raceName, race) == 0)
        {
            result++;
        }
    }

    return result;
}


/* 3.  */
void calculateScore(cyclist *p, const cycleRace *r, const int listLength)
{
    for(int i = 0; i <= listLength; i++)
    {
        /* Start by setting the score to 0 */
        p[i].points = 0;

        for(int j = 0; j < ARRAY_SIZE; j++)
        {
            if(strcmp(p[i].firstName, r[j].firstName) == 0 && strcmp(p[i].lastName, r[j].lastName) == 0)
            {
                /* The rider didnt DNF or OTL */
                if(r[j].placement > 0)
                {
                    /* Give 3 points plus some points based in the riders placement */
                    p[i].points += (3 + ((participants(r[j].raceName, r) - r[j].placement) / 13));

                    /* Give extra points to 1st 2nd and 3rd place */
                    if(r[j].placement == 1)
                    {
                        p[i].points += 10;
                    }
                    else if(r[j].placement == 2)
                    {
                        p[i].points += 5;
                    }
                    else if(r[j].placement == 3)
                    {
                        p[i].points += 2;
                    }
                }
                /* OTL */
                else if(r[j].placement == -1)
                {
                    p[i].points += 1;
                }
            }
        }
    }
}


/* Sorting function */
int cmpfunc(const void *a, const void *b)
{
    cyclist *p1, *p2;
    p1 = (cyclist*)a;
    p2 = (cyclist*)b;

    if(p1->points == p2->points)
    {
        return strcmp(p1->lastName, p2->lastName);
    }
    else if(p1->points < p2->points)
    {
        return 1;
    }
    else if(p1->points > p2->points)
    {
        return -1;
    }
    else
    {
        printf("[ERROR]: Something went wrong with cmpfunc");
        return 0;
    }
}

cyclist riderList[ARRAY_SIZE];
void sortByTop(cyclist *p, const int listLength)
{
    qsort(p, listLength, sizeof(cyclist), cmpfunc);
}