#include "stdio.h"

int main()
{
  //Print til og med 5
  for (int i = 0; i <= 5; i++)
  {
    for (int k = 0; k <= i; k++) {
      printf("%d ", k );
    }
    printf("\n");
  }

  //Print fra 4 til 0
  for (int i = 4; i >= 0; i--)
  {
    for (int k = 0; k <= i; k++)
    {
      printf("%d ", k );
    }
    printf("\n");
  }
  
  return 0;
}
