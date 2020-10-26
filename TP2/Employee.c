#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int initEmployees(Employee* list, int len)
{
    int retorno = -1;
    if (list != NULL && len > 0)
    {
        for (int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
**/

int addEmployee(Employee* list, int len, int id, char name[],char
                lastName[],float salary,int sector)
{
    int todoOk = 0;
    int index = buscarLibre(vec, qty);
    int existe;
    Employee auxEmpleado;

    system("cls");

    printf("***** Alta Empleado *****\n\n");

    if (index == -1) //hay lugar?
    {
        printf("No hay mas lugar en la lista\n");

    }
    else
    {
        auxEmpleado.id = idx;
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxEmpleado.name);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(auxEmpleado.lastName);

        printf("Ingrese salario: ");
        fflush(stdin);
        scanf("%f", &auxEmpleado.salary);

        printf("Ingrese sector: ");
        scanf("%d", &auxEmpleado.sector);

        auxEmpleado.isEmpty = 0;

        vec[index] = auxEmpleado;

        todoOk = 1;

    }
    return todoOk;
}


/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
    int index = -1;

    for(int i = 0; i < len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0 )
        {
            index = i;
            break;
        }
    }
    return index;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
    int id;
    int index;
    char confirmarBaja;

    system("cls");
    printf("***** BAJA EMPLEADO *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    index = buscarEmpleado(id, list, len);

    if( index == -1)
    {
        printf("No hay empleado con ese id %d\n", id );
    }
    else
    {
        mostrarEmpleado(list[index]);

        printf("\nConfirma la baja? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmarBaja);

        if( confirmarBaja == 's')
        {
            list[index].isEmpty = 1;
            printf("Se ha realizado la baja correctamente\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }

    }

}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
    Employee auxEmpleado;
    for (int i = 0; i < len -1; i++)
    {
        for (int j = i +1; j < len; j++)
        {
            if (list[i].sexo > list[j].sexo)                   // if (strcmp (list[i].nombre, list[j].nombre )> 0)   *** ordenamiento alfabetico

            {
                auxEmpleado = list[i];
                list[i] = list[j];
                list[j] = auxEmpleado;
            }
            else if (list[i].sexo == list[j].sexo && list[i].sueldo < list[j].sueldo)
            {
                auxEmpleado = list[i];
                list[i] = list[j];
                list[j] = auxEmpleado;
            }
        }
    }

}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length)
{
    return 0;
}

void mostrarEmpleado(eEmpleado x)
{
    printf("\n %d    %s   %c      %d      %.2f       %d/%d/%d \n",
           x.id, x.nombre, x.sexo, x.edad, x.sueldo,
           x.fechaIngreso.dia, x.fechaIngreso.mes, x.fechaIngreso.anio);
}

void mostrarEmpleados (eEmpleado vec[], int qty)
{
    int flag = 0;
    system("cls");
    printf("*****LISTADO DE EMPLEADOS*****\n\n");
    printf("   ID   NOMBRE   SEXO   EDAD   SUELDO   FECHAINGRESO\n");
    for(int i=0; i < qty; i++)
    {

        if( vec[i].isEmpty == 0)
        {
            mostrarEmpleado(vec[i]);
            flag = 1;
        }

    }
    if (flag == 0)
    {
        printf("\n ***No hay empleados que listar*** \n");

    }
}

int buscarLibre (eEmpleado vec[], int qty)
{
    int index = -1;
    for (int i = 0; i < qty; i++)
    {
        if(vec[i].isEmpty)
        {
            index = i;
            break;
        }
    }
    return  index;

    int buscarEmpleado (int id, eEmpleado vec[], int qty)
    {
        int index = -1;
        for(int i=0; i < qty; i++)
        {
            if(vec[i].id == id && vec[i].isEmpty == 0)
            {
                index = i;
            }
        }
        return index;
    }

}
int  altaEmpleado(int idx, eEmpleado vec[], int qty)
{
    int todoOk = 0;
    int index = buscarLibre(vec, qty);
    int existe;
    eEmpleado auxEmpleado;

    system("cls");

    printf("***** Alta Empleado *****\n\n");

    if (index == -1) //hay lugar?
    {
        printf("No hay mas lugar en la lista\n");

    }
    else
    {
        auxEmpleado.id = idx;
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxEmpleado.nombre);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &auxEmpleado.sexo);

        printf("Ingrese edad: ");
        fflush(stdin);
        scanf("%d", &auxEmpleado.edad);

        printf("Ingrese sueldo: ");
        scanf("%f", &auxEmpleado.sueldo);

        printf("Ingrese fecha ingreso: ");
        scanf("%d/%d/%d", &auxEmpleado.fechaIngreso.dia, &auxEmpleado.fechaIngreso.mes, &auxEmpleado.fechaIngreso.anio);

        auxEmpleado.isEmpty = 0;

        vec[index] = auxEmpleado;

        todoOk = 1;

    }
    return todoOk;
}



void  modificarEmpleado(eEmpleado vec[], int qty)
{
    int id;
    int index;
    char confimarModificacion;
    float nuevoSueldo;

    system("cls");
    printf("***** MODIFICACION EMPLEADO *****\n\n");
    printf("\n Ingrese id: ");
    scanf("%d", &id);


    index = buscarEmpleado(id, vec, qty);

    if( index == -1)
    {
        printf("No hay empleado con el id %d\n", id );
    }
    else
    {
        mostrarEmpleado(vec[index]);

        printf("\nModifica sueldo?  s/n: \n");
        fflush(stdin);
        scanf("%c", &confimarModificacion);

        if( confimarModificacion == 's')
        {
            printf("Ingrese el nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);

            vec[index].sueldo = nuevoSueldo;
            printf("Se ha realizado la operacion correctamente\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion.\n\n");
        }

    }

}
