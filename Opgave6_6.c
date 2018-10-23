#include<stdio.h>
#include<unistd.h>
#define USD_EURO 0.89
#define USD_KRONER 6.66
#define USD_RUBLE 66.43
#define USD_YEN 119.9

void convertDollars(double, double*, double*, double*, double*);

int main()
{
    double dollarInput, euro, kroner, rubler, yen;
    printf("Dollars: ");
    scanf(" %lf", &dollarInput);
    convertDollars(dollarInput, &euro, &kroner, &rubler, &yen);

    printf("Euro: %.2lf\nKroner: %.2lf\nRubler: %.2lf\nYen: %.2lf\n\n", euro, kroner, rubler, yen);
    sleep(3);

    for(double i = 1; i <= 100; i++)
    {
        convertDollars(i, &euro, &kroner, &rubler, &yen);
        printf("[%.0lf] Euro: %.2lf, Kroner: %.2lf, Rubler: %.2lf, Yen: %.2lf\n", i, euro, kroner, rubler, yen);
    }

    return 0;
}

void convertDollars(double dollar, double *euro, double *kroner, double *rubler, double *yen)
{
    *euro   = dollar * USD_EURO;
    *kroner = dollar * USD_KRONER;
    *rubler = dollar * USD_RUBLE;
    *yen    = dollar * USD_YEN;
}