#include<stdio.h>

int main() {
  double Humans = 9870;
  int Years = 0;

  do {
    Humans *= 1.1;
    Years++;
  } while(Humans < 30000);

  printf("It took %d years to reach 30000+, and the population reached %d\n", Years, Humans );

  return 0;
}
