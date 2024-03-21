#include "dynamic.h"
#include <stdio.h>
#include <stdlib.h>

/**
*   Implementación de la funcion
*   que calcula y obtiene la potencia de un numero usando libreria dinámica
* 
*   @param
*   - base: double - Representa el numero base que se le aplicará el exponente
*   - exp:  int - Representa el numero exponente que se aplicará a base
*
*   @return
*   - result: double
*/
double mypow_dynamic(double base, int exp)
{
    if (exp == 0)
        return 1.0;

    double result = base;

    // multiplico exp-1 veces la base
    for (int i = 0; i < abs(exp) - 1; ++i)
        result *= base;

    if (exp < 0)
        result = 1 / result;

    printf("[mypow_dynamic] result: %g\n", result);

    return result;
}
