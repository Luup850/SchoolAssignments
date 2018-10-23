#include<stdio.h>

#define SECINWEEK 604800; 
#define SECINDAY 86400;
#define SECINHOUR 3600;
#define SECINMIN 60;

int main(void)
{
    //Variables
    int inputSec = 0;
    int weeks = 0, days = 0, hours = 0, min = 0, sec = 0;
    int rest = 0;

    //Input
    printf("Input: ");
    scanf(" %d", &inputSec);
    printf("\n \n");


    //Calculations
    weeks   = inputSec / SECINWEEK;
    rest    = inputSec % SECINWEEK;

    days    = rest / SECINDAY;
    rest    = rest % SECINDAY;

    hours   = rest / SECINHOUR;
    rest    = rest % SECINHOUR;

    min     = rest / SECINMIN;
    rest    = rest % SECINMIN;

    sec     = rest;


    //Outputs
    printf(((weeks < 1) ? "" : ((weeks == 1) ? "%d week" : "%d weeks")), weeks);
    printf((days && hours && min && sec) == 0 ? "" : (days > 0 && (hours < 1 && min < 1 && sec < 1)) ? " and " : ", ");

    printf(((days < 1) ? "" : ((days == 1) ? "%d day" : "%d days")), days);
    printf((hours && min && sec) == 0 ? "" : (hours > 0 && (min < 1 && sec < 1)) ? " and " : ", ");

    printf(((hours < 1) ? "" : ((hours == 1) ? "%d hour" : "%d hours")), hours);
    printf((min && sec) == 0 ? "" : (min && !sec) ? " and " : ", ");

    printf(((min < 1) ? "" : ((min == 1) ? "%d minute" : "%d minutes")), min);
    printf((sec) == 0 ? "" : (sec > 0) ? " and " : ", ");

    printf(((sec < 1) ? "" : ((sec == 1) ? "%d second" : "%d seconds")), sec);
    printf("\n");

    return 0;
}