#include <stdio.h>
#include <math.h>   
double getDiscriminant(double, double, double); 
double getOneRoot(double, double); 
double getTwoRoots(double, double, double, int);
void solveQuadraticEquation(double, double, double);

int main(void) {
  
  double a = 1.0, b = -8.0, c = 15.0,
         d = 2.0, e =  8.0, f =  2.0,
         g, h, i;
  do
  {

    /* First call - coefficents are values of variables */
    solveQuadraticEquation(a, b, c);  

    /* Second call - coefficents are values of expressions */
    solveQuadraticEquation(d - 1, -e, 7 * f + 1); 

    /* Third call - coefficents are entered by user outside solveQuadraticEquation */
    printf("Enter coeficients a, b, and c: ");
    scanf("%lf %lf %lf", &g, &h, &i);

    if(g != 0 && h != 0 && i != 0)
      solveQuadraticEquation(g, h, i);  

  } while (g != 0 && h != 0 && i != 0);
  return 0;
}

double getDiscriminant(double a, double b, double c)
{
  return b * b - 4 * a * c;
}

double getOneRoot(double a, double b)
{
  return -b/(2*a);
}

double getTwoRoots(double a, double b, double discriminant, int isNegative)
{
  double value;
  if(isNegative)
  {
    value = (-b - sqrt(discriminant))/(2*a);
  }
  else
  {
    value = (-b + sqrt(discriminant))/(2*a);
  }
  return value;
}

/* Prints roots of the quadratic equation a * x*x + b * x + c = 0 */
void solveQuadraticEquation(double a, double b, double c){
  
  double discriminant;

  discriminant = getDiscriminant(a, b, c);

  if (discriminant < 0)
    printf("No roots\n");
  else if (discriminant == 0){
    printf("One root: %f\n", getOneRoot(a, b));
  }
  else {
    printf("Two roots: %f and %f\n", getTwoRoots(a, b, discriminant, 0), getTwoRoots(a, b, discriminant, 1));
  }
}