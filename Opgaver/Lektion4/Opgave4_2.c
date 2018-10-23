#include <stdio.h>

int main() {
  int m, n, k, largest, smallest, sum = 0;

  printf("Input m n k:");
  scanf("%d %d %d", &m, &n, &k );

  if (k < 1)
  {
    printf("U done goof. K > 0 or shit hits the fan");
    return 0;
  }

  //Find ud af hvilken værdi der er størst og mindst.
  if (m > n)
  {
    largest = m;
    smallest = n;
  }
  else
  {
    largest = n;
    smallest = m;
  }

  //Læg alle tallene mellem m og n sammen hvis de går op i k
  for (int i = smallest; i <= largest; i++)
  {
    if((i % k) == 0)
    {
      sum += i;
    }
  }

  printf("Output: %d\n", sum );

  return 0;
}
