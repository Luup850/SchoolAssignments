#include<stdio.h>

int main() {

int input, sum = 0;
printf("Input number: ");
scanf("%d\n", &input );

  for (int i = 1; i <= input; i++) {
    sum += 1;
    if (input = (input * (input + 1)) / 2)
    {
      printf("[%d] It's true\n", i);
    }
    else
    {
      printf("[%d] It's not true\n", i);
    }
  }

  printf("Done...\n");
  return 0;
}
