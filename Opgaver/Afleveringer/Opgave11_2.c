#include<stdio.h>
#include<ctype.h>
#include<string.h>

/* Prototypes */
int is_palindrome_iter(char*);
int is_palindrome_rec(char*, int);

int main(void)
{
    /* Variables */
    char input[20];
    int length;

    /* Get user input */
    printf("Enter the word you want to check: ");
    scanf(" %s", input);
    length = strlen(input) - 1;

    /* Print result */
    printf("Iterativ: %d \nRekursiv: %d\n", is_palindrome_iter(input), is_palindrome_rec(input, length));

    return 0;
}

/* Function that test if its a palindrome by using iteration */
int is_palindrome_iter(char *word)
{
    int len = strlen(word) - 1;
    /* For loop that runs until we reach the middle of the string */
    for(int i = 0, j = len; i <= len / 2; i++, j--)
    {
        /* If the two char's are not the same. Return false */
        if(word[i] != word[j])
        {
            return 0;
        }
    }
    /* We've reached the end of the for loop, so it must be a palindrome. Return true */
    return 1;
}

/* Function that test if its a palindrome by using recursion */
int is_palindrome_rec(char *word, int len)
{
    /* If we've reached the middle of the string,    
       and the two chars are the same. Then it must  
       be a palindrome                              */
    if(word[0] == word[len] && len <= 2)
    {
        return 1;
    }
    /* Keep checking the string if the two char's are the same */
    else if(word[0] == word[len])
    {
        return (is_palindrome_rec(word += 1, len-2));
    }
    /* Wasn't a palindrome. Return false */
    else
    {
        return 0;
    }
}