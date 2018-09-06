#include "Libreria.h"
#include  <stdio.h>

/**
 * \brief Suma de dos operandos.
 * \param a Primer operando a sumar.
 * \param b Segundo operando a sumar.
 * \return Total de la suma.
 *
 */

float suma(float a, float b)
{
    return (a+b);
}

/**
 * \brief Resta de dos operandos.
 * \param a Primer operando a restar.
 * \param b Segundo operando a restar.
 * \return Total de la resta.
 *
 */

float resta(float a, float b)
{
    return (a-b);
}

/**
 * \brief Multiplicación de 2 operandos
 * \param a Primer operando a multiplicar.
 * \param b Segundo operando a multiplicar.
 * \return Total de la multiplicación
 *
 */

float multiplicacion(float a, float b)
{
    return (a*b);
}

/**
 * \brief División de 2 operando.
 * \param a Primer operando a dividir.
 * \param b Segundo operando a dividir.
 * \return Total de la división.
 *
 */

float division(float a, float b)
{
    return a/b;
}

/**
 * \brief Factorial de 1 operando.
 * \param Número a factoriar.
 * \return Total del factorial.
 *
 */

int factorial (int numero)
{
    int fact = 1;
    if(numero==0)
    {
        return 1;
    }
    else if(numero<0)
    {
        return 0;
    }
    else
    {
        for(int i=1;i<=numero;i++)
        {
             fact*=i;
        }
    }
    return fact;
}
