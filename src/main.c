// A simple program that computes the square root of a number
#include <MathFunctions.h>
#include <dynamic.h>
#include <math.h>
#include <static.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    printf("step 1 - Bienvenido a main de lab0-SO2-2024\n");

    printf("step 2 - Se incorpora libreria propia de pow\n");

    double inputValue_base = 0;
    int inputValue_exp = 0;

    printf("[main] ingrese base: ");
    scanf("%lf", &inputValue_base);

    printf("[main] ingrese exponente: ");
    scanf("%d", &inputValue_exp);

    printf("[main] El resultado de elevar %g a la %d se muestran a continuación\n", inputValue_base, inputValue_exp);

    mypow(inputValue_base, inputValue_exp);

    printf("step 3 - Se incorpora librerias STATIC DYNAMIC de pow\n");

    mypow_static(inputValue_base, inputValue_exp);
    mypow_dynamic(inputValue_base, inputValue_exp);

    return 0;
}
