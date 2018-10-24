#include<stdio.h>
#include<math.h>

/*  ----------[Prototypes]----------
*   Prototypes for the two functions
*/
double trap(double, double, int, double(*)(double));
double getYCoordinate(double);

/*  ------[Main]-----
*   The main function
*/
int main(void)
{
    /* Declare user input variables */
    double a, b, n;

    /* Ask user for inputs */
    printf("Please input a, b, n in the following form\n<a b n>\n");
    scanf(" %lf %lf %lf", &a, &b, &n);

    /* Print the area under the defined graph for the defined interval */
    printf("The sum under the graph is: %lf", trap(a, b, n, getYCoordinate));

    return 0;
}

/*  ----------[Function]--------------
*   Calculate the area under the graph
*/
double trap(double a, double b, int n, double(*f)(double x))
{
    double h = (b - a) / n;
    double sum = 0;

    /* Slice the graph in to n pieces of times */
    for(int i = 0; i < n; i++)
    {
        /* Get the sum of all the pieces */
        sum += f(a + ((b - a) / n) * i);
    }

    /* Calculate the area and return it */
    return (h / 2) * (f(a) + f(b) + 2 * sum);
}

/*  ---------[Function]-------------
*   The equation that we want to use
*/
double getYCoordinate(double x)
{
    return sqrt(4-powf(x, 2));
}