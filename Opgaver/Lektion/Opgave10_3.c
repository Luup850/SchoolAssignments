#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Prototypes */
char *convertString(char *string);

int main(void)
{
    char input[40];

    printf("Please enter a singular noun to be converted to plural noun:\n");
    scanf(" %s", input);

    printf("\n%s\n", convertString(input));

    return 0;
}

/* Convert singular noun to plural nouns */
char *convertString(char *string)
{
    int stringLength = strlen(string);

    /* Check if the last char is y */
    if(string[stringLength - 1] == 'y')
    {
        /* Remove y and add 'ies' to string */
        string[stringLength - 1] = '\0';
        strcat(string, "ies");
    }
    else if(string[stringLength - 1] == 's')
    {
        strcat(string, "es");
    }
    else if((string[stringLength - 2] == 'c' && string[stringLength - 1] == 'h') ||
    (string[stringLength - 2] == 's' && string[stringLength - 1] == 'h'))
    {
        strcat(string, "es");
    }
    else
    {
       strcat(string, "s"); 
    }

    return string;
}

