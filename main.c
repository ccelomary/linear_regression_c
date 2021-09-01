#include <stdio.h>
#include "linear_regression.h"

int     main(void)
{
    t_linear_regression     regressor;
    double                  input[100];
    double                  output[100];
    FILE                    *file;
    int                     iterator;

    file = fopen("data.csv", "r");
    iterator = 0;
    // y = ax + b
    while (!feof(file))
    {
        fscanf(file, "%lf,%lf\n", input + iterator, output + iterator);
        iterator++;
    }
    regressor = init_linear_regression(0.0001, 10000);
    train_linear_regression(&regressor, input, output, 100);
    printf("%lf %lf\n", regressor.alpha, regressor.b);
    return (0);
}