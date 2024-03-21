#include "MathFunctions.h"
#include <stdio.h>
#include <stdlib.h>

/**
*   Funcion que calcula y obtiene la potencia de un numero
*   @param
*   - base: double
*   - exp:  int
*
*   @return
*   - result: int
*/
double mypow(double base, int exp)
{
    if (exp == 0)
        return 1.0;

    double result = base;

    // multiplico exp-1 veces la base
    for (int i = 0; i < abs(exp) - 1; ++i)
        result *= base;

    if (exp < 0)
        result = 1 / result;

    printf("[mypow] result: %g\n", result);

    return result;
}
