#include "stdio.h"

int main()
{
  //Variables.
  int inputA = 0, inputB = 0, smallest = 0, largest = 0;

  do
  {
    //Get user input.
    printf("Input format is <a b>.\nTo exit the program, set one of the integers to a negative number\n");
    printf("Input: ");
    scanf("%d %d", &inputA, &inputB);

    //Check which input is largest.
    if (inputA > inputB)
    {
      largest = inputA;
      smallest = inputB;
    }
    else
    {
      largest = inputB;
      smallest = inputA;
    }
    
    //Check which number is the largest number that can be divided with input a and b.
    if ((inputA >= 0) && (inputB >= 0))
    {
      for (int i = smallest; i >= 1; i--)
      {
        if (((smallest % i) == 0) && ((largest % i) == 0))
        {
          printf("The biggest number that that can be divided with %d and %d is: %d\n\n", inputA, inputB, i );
          i = 0; //To stop the for loop
        }
      }
    }
  } while ((inputA >= 0) && (inputB >= 0));

  printf("\nOne of the inputs was a negative number.\nExiting program\n");
  return 0;
}
