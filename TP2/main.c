#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"

#define QTY 3

int main()
{
    int menu();
    int proximoId = 0;

    char seguir = 's';
    char confirmarSalida;

    Employee anEmployee[QTY];

    initEmployees(anEmployee, QTY);

    do
    {
        switch(menu())
        {
        case 1:
            if (altaEmpleado(proximoId, anEmployee, QTY))
            {
                proximoId++;
            }
            break;
        case 2:
            modificarEmpleado(anEmployee, QTY);
            break;
        case 3:
            bajaEmpleado(anEmployee, QTY);
            break;
        case 4:
            printf("Ordenar\n\n");
            break;
        case 5:
            mostrarEmpleados(anEmployee, QTY);
            break;
        case 6:
            printf("Informes\n\n");
            break;
        case 7:
            printf("Confirma salida? s/n\n\n");
            fflush(stdin);
            scanf("%c", &confirmarSalida);
            if(confirmarSalida == 's')
            {
                seguir = 'n';
            }
            break;

        }
        system("pause");
    }while( seguir == 's');

    return 0;
}



int menu()
{
    int opcion;
    system("cls");
    printf("****** Gestion de Empleados *****\n\n");
    printf("1. Alta Empleado\n");
    printf("2. Modificar Empleado\n");
    printf("3. Baja Empleado\n");
    printf("4. Ordenar Empleados\n");
    printf("5. Listar Empleados\n");
    printf("6. Informes\n");
    printf("7. Salir\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;


}
