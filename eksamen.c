/*
    Opgave 1:
    Find og udskriv løbsresultaterne for alle italienske cykelryttere over 30 år. 
    I denne opgave er det OK at lave en funktion som blot printer resultaterne direkte

    Opgave 2:
    Skriv en funktion som returnerer et array af alle de danske ryttere,
    som har gennemført et eller flere af de fire cykelløb,
    enten med en placering eller med OTL. Kald funktionen,
    og udskriv disse danske ryttere samt hvor mange løb hver af de danske
    ryttere har gennemført. Bemærk, at hver rytter kun ønskes udskrevet en gang.

    Opgave 3:
    Udskriv de 10 ryttere som har opnået flest point.
    Sorter primært rytterne efter antal point.
    Ved pointlighed sorteres rytterne alfabetisk efter efternavn. 
    (Efternavnet er den del af rytterens navn som er skrevet med udelukkende store bogstaver.
    Bemærk at efternavnet også kan indeholde mellemrum og specialtegn).

    Opgave 4:
    I denne opgave fokuseres på de to cykelløb Paris Roubaix og Amstel Gold Race.
    Skriv en funktion som finder den rytter, som har gennemført begge disse løb,
    og som har den mindste samlede køretid i de to løb.
    Funktionen skal have rytteren og den samlede køretid som outputparametre.
    Kald funktionen og udskriv rytterens navn og den samlede køretid (i timer, minutter og sekunder).

    Opgave 5:
    Beregn gennemsnitsalderen (af typen double) blandt alle de ryttere,
    som har opnået en topti placering i et eller flere cykelløb. 
    Vær sikker på at ryttere, som har et top-ti resultat i to eller flere 
    af de fire løb, ikke indgår mere én gang i gennemsnitsberegningen.


    Program udarbejdet af Marcus D. Christiansen.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h> /* Isupper */

/* Anti magic number system */
#define MAX_NAME_SIZE 40
#define MAX_TEAM_NATIONALITY_NAME 4
#define ARRAY_SIZE 790
#define INPUT_FILE "cykelloeb"
#define OTL -1
#define DNF -2

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
    int temporary;
    int temporary2;
};


/* Type defines */
typedef struct cycleRace cycleRace;
typedef struct cyclist cyclist;


/* Prototypes */
void loadDataSet(const char *dataSet, cycleRace *r);
void printNationalResults(const cycleRace *r, const char nat[4], const int overAge, const int underAge);
int createUniqueList(const cycleRace *r, cyclist *p);
char* getStringOfRiders(const cyclist *p, const int listLength, const int minRaceComp, const char *nat);
int participants(const char *race, const cycleRace *r);
void calculateScore(cyclist *p, const cycleRace *r, const int listLength);
void sortByTop(cyclist *p, const int listLength);
int cmpfunc(const void *a, const void *b);
void getBestAvg(const char *rName1, const char *rName2, const cycleRace *r, const int listLength, cyclist *p, int *bestRider, int timeOfCyclist[]);
double getAvgAge(const int riderAmount, const cycleRace *r);


/* Main function */
int main(int argc, char const *argv[])
{
    /* Arrays */
    cycleRace raceList[ARRAY_SIZE];
    cyclist riderList[ARRAY_SIZE];
    /* ---------------------------------------------------- */


    /* Variables */
    char *listOfDanes;
    int bestRider;
    int timeOfCyclist[3];
    /* ---------------------------------------------------- */


    /* Initialization */
    loadDataSet(INPUT_FILE, raceList);
    int u = createUniqueList(raceList, riderList);
    calculateScore(riderList, raceList, u);
    sortByTop(riderList, u);
    listOfDanes = getStringOfRiders(riderList, u, 1, "DEN");
    /* ---------------------------------------------------- */
    

    /* Main */
    int menuVar = 0;


    if(strcmp(argv[1], "--print") == 0)
    {
        menuVar = -1;

        /* Opgave 1 */
        printf("Opgave 1:\n");
        printNationalResults(raceList, "ITA", 30, 99);

        /* Opgave 2 */
        printf("\n\nOpgave 2:\nAntal loeb \tNavn\n");
        printf("%s", listOfDanes);

        /* Opgave 3 */
        printf("\n\nOpgave 3:\n");
        printf("--------------------------------------------\nPosition \t|  Name \t|  Points\n--------------------------------------------\n");
        for(int i = 0; i < 10; i++)
        {
            printf("Placement: %-4d %-20s %-20s %10d\n", i+1, riderList[i].firstName, riderList[i].lastName, riderList[i].points);
        }

        /* Opgave 4 */
        getBestAvg("ParisRoubaix" ,"AmstelGoldRace", raceList, u, riderList, &bestRider, timeOfCyclist);
        printf("\n\nOpgave 4:\n");
        printf("The best rider in ParisRoubaix and Amstel Gold Race is: %s ", riderList[bestRider].firstName);
        printf("%s\n", riderList[bestRider].lastName);
        printf(", with the time %d:%d:%d\n", timeOfCyclist[0], timeOfCyclist[1], timeOfCyclist[2]);

        /* Opgave 5 */
        printf("\n\nOpgave 5:\n");
        printf("Avg age of top %d for all the races is: %0.2lf\n", 10, getAvgAge(10, raceList));
    }

    while(menuVar != -1)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\nChoose which assignment you want to run (1-5) \nTo exit the program enter -1\n");
        scanf(" %d", &menuVar);
        if(menuVar == 1)
        {
            /* Opgave 1 */
            printf("Opgave 1:\n");
            printNationalResults(raceList, "ITA", 30, 99);
        }
        else if(menuVar == 2)
        {
            /* Opgave 2 */
            printf("\n\nOpgave 2:\nAntal loeb \tNavn\n");
            printf("%s", listOfDanes);
        }
        else if(menuVar == 3)
        {
            /* Opgave 3 */
            printf("\n\nOpgave 3:\n");
            printf("--------------------------------------------\nPosition \t|  Name \t|  Points\n--------------------------------------------\n");
            for(int i = 0; i < 10; i++)
            {
                printf("Placement: %-4d %-20s %-20s %10d\n", i+1, riderList[i].firstName, riderList[i].lastName, riderList[i].points);
            }
        }
        else if(menuVar == 4)
        {
            /* Opgave 4 */
            getBestAvg("ParisRoubaix" ,"AmstelGoldRace", raceList, u, riderList, &bestRider, timeOfCyclist);
            printf("\n\nOpgave 4:\n");
            printf("The best rider in ParisRoubaix and Amstel Gold Race is: %s ", riderList[bestRider].firstName);
            printf("%s\n", riderList[bestRider].lastName);
            printf(", with the time %d:%d:%d\n", timeOfCyclist[0], timeOfCyclist[1], timeOfCyclist[2]);
        }
        else if(menuVar == 5)
        {
            /* Opgave 5 */
            printf("\n\nOpgave 5:\n");
            printf("Avg age of top %d for all the races is: %0.2lf\n", 10, getAvgAge(10, raceList));
        }

        if(menuVar != -1)
        {
            printf("\nType 'r' to return to the menu\n");
            scanf(" r");
        }
    }

    free(listOfDanes);
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
            r[i].placement = DNF;
            r[i].trackTimeHours = 0;
            r[i].trackTimeMin = 0;
            r[i].trackTimeSec = 0;
            fscanf(f, " -");
        }
        else if(strcmp(temp, "OTL") == 0)
        {
            r[i].placement = OTL;

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

            if(r[i].placement == OTL)
                printf("OTL\t| ");
            else if(r[i].placement == DNF)
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

                if(r[i].placement > DNF)
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
            strcpy(p[uniquePerson].lastName, r[i].lastName);
            p[uniquePerson].age = r[i].age;
            strcpy(p[uniquePerson].nationality, r[i].nationality);

            /* If this unique rider didnt DNF then increase completed races to 1 */
            if(r[i].placement > DNF)
            {
                p[uniquePerson].numberOfCompletedRaces = 1;
            }

            /* Count up uniquePerson since this is the first time we've found this rider */
            uniquePerson++;
        }
    }
    /* Return how many unique people there is in the list */
    return uniquePerson;
}


/*----------------------------------------------------------------
    2. Return a list of all riders with a specific nationality 
----------------------------------------------------------------*/
char* getStringOfRiders(const cyclist *p, const int listLength, const int minRaceComp, const char *nat)
{
    char buffer[20];
    char *resToReturn;
    int counter = 0;

    for(int i = 0; i <= listLength; i++)
    {
        /* Check if the current rider matches with the specifications given */
        if(strcmp(p[i].nationality, nat) == 0 && p[i].numberOfCompletedRaces >= minRaceComp)
        {
            counter += 3;
        }
    }

    resToReturn = (char*)calloc(counter, MAX_NAME_SIZE);

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

    return resToReturn;
}


/*------------------------------------------------ 
    Calculate number of participants in a race 
------------------------------------------------*/
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


/*----------------------------------------------------
    3. Calculate the combined score of all riders 
----------------------------------------------------*/
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


/*--------------------------
    3. Sorting function 
--------------------------*/
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


/*--------------------------------------
    3. Sort the list by most points 
--------------------------------------*/
void sortByTop(cyclist *p, const int listLength)
{
    qsort(p, listLength, sizeof(cyclist), cmpfunc);
}


/*----------------------------------------------------------------
    4. Get the rider with the best combined time from 2 races
----------------------------------------------------------------*/
void getBestAvg(const char *rName1, const char *rName2, const cycleRace *r, const int listLength, cyclist *p, int *bestRider, int timeOfCyclist[])
{
    int saveForLater = -1;
    int bestTime = 0;
    int rest = 0;

    /* Reset the temp variables */
    for(int i = 0; i <= listLength; i++)
    {
        p[i].temporary = -1;
        p[i].temporary2 = 0;
    }


    for(int i = 0; i <= listLength; i++)
    {
        for(int j = 0; j < ARRAY_SIZE; j++)
        {
            /* Check if first name and last name matches in both arrays of structs */
            if(strcmp(p[i].firstName, r[j].firstName) == 0 && strcmp(p[i].lastName, r[j].lastName) == 0)
            {
                /* Check if the races matches either rName1 or rName2 and check that they didnt DNF */
                if( r[j].placement >= 1 && (strcmp(r[j].raceName, rName1) == 0 || strcmp(r[j].raceName, rName2) == 0))
                {
                    p[i].temporary2 = p[i].temporary2 + 1;
                    p[i].temporary = p[i].temporary + (r[j].trackTimeHours * 60 * 60);
                    p[i].temporary = p[i].temporary + (r[j].trackTimeMin * 60);
                    p[i].temporary = p[i].temporary + r[j].trackTimeSec;
                }
            }
        }
    }

    /* Find the best time for the two races */
    for(int i = 0; i <= listLength; i++)
    {
        if((saveForLater > p[i].temporary || saveForLater < 0) && p[i].temporary2 == 2)
        {
            bestTime = i;
            saveForLater = p[i].temporary;
        }
    }

    /* Calculate the seconds back to hours, min and sec */
    timeOfCyclist[0] = p[bestTime].temporary / (60 * 60);
    rest = p[bestTime].temporary % (60 * 60);

    timeOfCyclist[1] = rest / 60;
    rest = rest % 60;

    timeOfCyclist[2] = rest;

    *bestRider = bestTime;
}


/*----------------------------------------------------------------
    5. Get the avg age of top 10 for all the races
----------------------------------------------------------------*/
double getAvgAge(const int riderAmount, const cycleRace *r)
{
    double sum = 0;
    int amount = 0;
    char fullName[80];
    char temp[3200];

    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        /* Make a string of their full name */
        fullName[0] = '\0';
        strcat(fullName, r[i].firstName);
        strcat(fullName, " ");
        strcat(fullName, r[i].lastName);

        /* Check if we've already counted them */
        if(strstr(temp, fullName) == '\0' && r[i].placement >= riderAmount)
        {
            /* If we didnt count them, then add them to the string and get their age */
            strcat(temp, fullName);
            strcat(fullName, ", ");
            sum += r[i].age;
            amount++;
        }
    }

    /* Return the average age */
    return (sum / amount);
}