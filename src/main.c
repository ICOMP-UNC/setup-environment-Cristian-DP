// A simple program that computes the square root of a number
#include <MathFunctions.h>
#include <dynamic.h>
#include <math.h>
#include <static.h>
#include <stdio.h>
#include <stdlib.h>

/**
*   Funcion main.
* 
*   @param
*   - argc:     int     - Cantidad de argumentos pasado a la funcion main
*   - *argv[]:  char    - Puntero a la lista de argumentos
*
*   @return
*   - result: int
*/
int main(int argc, char *argv[])
{

    printf("step 1 - Bienvenido a main de lab0-SO2-2024\n");

    printf("step 2 - Se incorpora libreria propia de pow\n");

    double input_Value_base = 0;
    int input_Value_exp = 0;

    printf("[main] ingrese base: ");
    scanf("%lf", &input_Value_base);

    printf("[main] ingrese exponente: ");
    scanf("%d", &input_Value_exp);

    printf("[main] El resultado de elevar %g a la %d se muestran a continuación\n", input_Value_base, input_Value_exp);

    mypow(input_Value_base, input_Value_exp);

    printf("step 3 - Se incorpora librerias STATIC DYNAMIC de pow\n");

    mypow_static(input_Value_base, input_Value_exp);
    mypow_dynamic(input_Value_base, input_Value_exp);

    return 0;
}
