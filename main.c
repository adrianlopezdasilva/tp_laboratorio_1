#include <stdio.h>
#include <stdlib.h>
#include "Libreria.h"

int main()
{
    float x;
    float y;
    int banderaUno = 0;
    int banderaDos = 0;
    int banderaTres = 0;
    int menu;
    int banderaSalida = 0;


    do
    {
        system("cls");
        printf("Elija una opcion\n\n");
        if(banderaUno==0)
        {
            printf("1. Ingrese el primer operando (A=x)\n");
        }
        else
        {
            printf("1. Ingrese el primer operando (A=%.2f)\n", x);
        }
        if(banderaDos==0)
        {
            printf("2. Ingrese el segundo operando (B=y)\n\n");
        }
        else
        {
            printf("2. Ingrese el segundo operando (B=%.2f)\n\n", y);
        }
        printf("3. Calcular operaciones: \na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division (A/B)\n");
        printf("d) Calcular la multiplicacion (A*B)\ne) Calcular el factorial (A!)\n");
        printf("\n4. Mostrar resultados\n");
        printf("5. Salir\n");
        scanf("%d", &menu);

        switch(menu)
        {
                case 1:
                        system("cls");
                        printf("1. Ingrese el primer operando (A=x)\n");
                        fflush(stdin);
                        scanf("%f", &x);
                        banderaUno=1;
                        break;
                case 2:
                        system("cls");
                        printf("2. Ingrese el segundo operando (B=y)\n)");
                        fflush(stdin);
                        scanf("%f", &y);
                        banderaDos=1;
                        break;
                case 3:
                        if(banderaUno!=1)
                        {
                            printf("Debe ingresar operando A\n");
                            printf("1. Ingrese el primer operando (A=x)\n");
                            fflush(stdin);
                            scanf("%f", &x);
                            banderaUno=1;
                        }
                        if(banderaDos!=1)
                        {
                            printf("Debe ingresar operando B\n");
                            printf("2. Ingrese el segundo operando (B=y)\n)");
                            fflush(stdin);
                            scanf("%f", &y);
                            banderaDos=1;
                        }
                        system("cls");
                        printf("\ncalculando...\n\n");
                        suma(x, y);
                        resta(x, y);
                        division(x, y);
                        multiplicacion(x, y);
                        factorial(x);
                        factorial(y);
                        banderaTres = 1;
                        system("pause");
                        break;

                case 4:
                        if(banderaTres!=1)
                        {
                            printf("Primero debe hacer los calculos con la opcion 3\n");
                            system("pause");
                        }
                        else
                        {
                            system("cls");
                            printf("Resultados:\n");
                            printf("\n1er operando (A=%.2f)\n", x);
                            printf("el segundo operando (B=%.2f)\n\n", y);
                            printf("El resultado de A+B es: %.2f", suma(x, y));
                            printf("\nEl resultado de A-B es: %.2f", resta(x, y));
                        }
                        if(y==0)
                        {
                            printf("\nEl resultado de A/B es: No es posible dividir por cero!");
                        }
                        else
                        {
                            printf("\nEl resultado de A/B es: %.2f", division(x, y));
                        }
                        printf("\nEl resultado de A*B es: %.2f", multiplicacion(x, y));
                        printf("\nEl factorial de A es: %d", factorial(x));
                        printf("\nEl factorial de B es: %d\n\n", factorial(y));
                        system("pause");
                        break;
                case 5:
                        banderaSalida=1;
                        printf("\nAprete Enter para salir\n");
                        break;
        }

    }
    while(banderaSalida==0);

    return 0;
}


