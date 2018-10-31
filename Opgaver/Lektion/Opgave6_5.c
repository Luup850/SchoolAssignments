#include<stdio.h>
#include<math.h>
void scan_data(char*, double*);
double do_next_op(char, double, double);

int main()
{
    double inputDouble, result = 0;
    char inputChar;

    do
    {
        printf("Please enter an operater and a number:\n");
        scan_data(&inputChar, &inputDouble);

        if(inputChar != 'q')
        {
            result = do_next_op(inputChar, inputDouble, result);
            printf("%lf\n\n", result);
        }

    } while(inputChar != 'q');
    return 0;
}

void scan_data(char *a, double *b)
{
    scanf(" %c %lf", a, b);
}

double do_next_op(char a, double b, double result)
{
    switch (a)
    {
        case '+':
            result = result + b;
            break;
        case '-':
            result = result - b;
            break;
        case '*':
            result = result * b;
            break;
        case '/':
            result = result / b;
            break;
        case '^':
            result = pow(result, b);
            break;
        default:
            printf("Error");
            break;
    }
    return result;
}