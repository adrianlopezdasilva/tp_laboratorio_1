/*
 * Employee.c
 *
 *  Created on: 2020/10/02
 *      Author: PC
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"

/**
 * \brief Genera un nuevo id y lo incrementa cada vez que sea necesario
 * \return el id a utilizar
 */
static int employee_generarNuevoId (void)
{
	static int id = 0;
	id = id+1;
	return id;
}

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

	if(list != NULL && len >0)
	{
		for (int i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
* 		   in the first empty position
* \param list employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len)
{
	int retorno = -1;
	int indice;
	Employee bufferEmployee;

	if(list != NULL && len > 0)
	{
		if(employee_buscarLibreRef(list, len,&indice ) == 0)
		{
			if(utn_getNombre("Ingrese el nombre del cliente: ", "\n Ese no es un nombre valido\n",bufferEmployee.name, 2, 51)==0 &&
				utn_getNombre("Ingrese un apellido del cliente: ", "\n Ese no es un apellido valido\n",bufferEmployee.lastName, 2, 51)==0 &&
				utn_getFloat("Ingrese el salario del cliente: ", "\nEse salario esta fuera del rango\n",&bufferEmployee.salary, 2, 1,50000)==0 &&
				utn_getNumero("Ingrese el sector del cliente:","\n Ese no es un sector valido\n",&bufferEmployee.sector,2,1,10)==0)
			{
				list[indice] = bufferEmployee;
				list[indice].id = employee_generarNuevoId();
				list[indice].isEmpty = FALSE;
				retorno = 0;
			}
			else
			{
				printf("Surgio un error");
			}
		}
		else
		{
			printf("No se encontro un lugar libre");
		}
	}
	return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param id int
* \param pIndice int* El puntero donde se va a guardar el indice deseado
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id, int* pIndice)
{
	int retorno = -1;

	if(list != NULL && len > 0 && id > 0 && pIndice != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE &&
			   list[i].id == id )
			{
				*pIndice = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Busca un lugar libre en el array de employee y lo pasa por puntero
* \param list Employee*  Pointer to array of employees
* \param len int Array length
* \param pIndice int* El puntero donde se va a guardar el indice deseado
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int employee_buscarLibreRef (Employee* list, int len, int* pIndice)
{
	int retorno = -1;

	if(list != NULL && len > 0 && pIndice != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				*pIndice = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Modifica los campos del empleado deseado
* \param list Employee*  Pointer to array of employees
* \param len int Array length
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*/
int modifyEmployee(Employee* list, int len)
{
	int retorno = -1;
	int auxIndice;
	int indiceAModificar;
	Employee bufferEmployee;

		if(list != NULL && len > 0)
		{
			printEmployees(list, len);
			if (utn_getNumero("\nIngrese el ID del empleado a modificar: ", "\n Ese no es un nombre valido\n",&auxIndice, 5, 1, 1000) == 0 &&
				findEmployeeById(list, len, auxIndice,&indiceAModificar ) == 0 )
			{
				bufferEmployee = list[indiceAModificar];
				if(utn_getNombre("Ingrese el nuevo nombre del empleado: ", "\nEse no es un nombre valido\n",bufferEmployee.name, 2, 51)==0 &&
				   utn_getNombre("Ingrese un nuevo apellido del empleado: ", "\nEse no es un apellido valido\n",bufferEmployee.lastName, 2, 51)==0 &&
					utn_getFloat("Ingrese el nuevo salario del empleado: ", "\nEse no es un salario valido\n",&bufferEmployee.salary, 2, 1,100000)==0 &&
					utn_getNumero("Ingrese el nuevo sector del empleado:","\nEse no es un sector valido\n",&bufferEmployee.sector,2,1,10)==0)
				{
					list[indiceAModificar] = bufferEmployee;
					retorno = 0;
					printf("\n Modificacion realizada con exito\n");
				}
			}
			else
			{
				printf("Surgio un error");
			}
		}

	return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;

	if(list != NULL && len > 0 && order > 0)
	{
		int i;
		int j;
		Employee bufferEmployee;

		for(i=0; i<len-1; i++)
		{
			for(j=i+1; j<len; j++)
			{
				if((order == 1 && strcmp(list[i].lastName,list[j].lastName)>=1) ||
				   (order == 2 && strcmp(list[i].lastName,list[j].lastName)<=-1) ||
				   (strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector > list[j].sector))
				{
					bufferEmployee = list[i];
					list[i] = list[j];
					list[j] = bufferEmployee;
				 }
			 }
		 }
			printf("\n Reordenamiento logrado con exito\n");
			retorno = 0;
	}

	return retorno;
}

/** \brief print the content of employees array
* \param list Employee* Pointer to array of employees
* \param leghtn int Array length
* \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int printEmployees(Employee* list, int length)
{
	int retorno = -1;

	if(list != NULL && length > 0)
	{
		for(int i= 0; i < length; i ++ )
			{
				if(list[i].isEmpty == FALSE)
				{
					printf("\nNombre: %s   Apellido: %s   Salario: %.2f    Sector: %d    Id: %d",
							list[i].name, list[i].lastName, list[i].salary, list[i].sector, list[i].id);
				}
			}
		retorno = 0;
	}
	return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len)
{
	int retorno = -1;
	int flagConfirmacion = 2;
	int auxIndice;
	int indiceAModificar;

	if(list != NULL && len > 0 )
	{
		printEmployees(list, len);
		if (utn_getNumero("\nIngrese el ID del empleado a modificar: ", "\n Ese no es un ID valido\n",&auxIndice, 5, 1, 1000) == 0 &&
			findEmployeeById(list, len, auxIndice,&indiceAModificar ) == 0 )
		{
			if(utn_getNumero("\nEsta seguro que quiere dar de baja este empleado? \n1-Si\n2-No\n ",
							"\n Ese no es un nombre valido\n",&flagConfirmacion, 5, 1, 1000) ==0 &&
							flagConfirmacion == 1)
			{
				list[indiceAModificar].isEmpty = TRUE;
				retorno = 0;
			}
			else if (flagConfirmacion == 2)
			{
				printf("Operacion abortada");
			}
		}
	}
	return retorno;
}
/** \brief Calcula el total y el promedio de los empleados del array los imprime por pantalla
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*/
int salarioTotalYPromedio(Employee* list, int len)
{
	int retorno = -1;
	float totalSalario = 0;
	float promedioSalario = 0;
	int contador = 0;
	int contadorEmpleados= 0;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				totalSalario = totalSalario + list[i].salary;
				contador++;
			}
		}

		promedioSalario = totalSalario / contador;

		for(i = 0; i < len; i++)
		{
			if(list[i].salary > promedioSalario)
			{
				contadorEmpleados++;
			}
		}
		retorno = 0;
	}

	printf("\n\nEl salario total es %2.f, el promedio es %.2f y hay %d empleados por encima de de el",totalSalario,promedioSalario,contadorEmpleados);
	return retorno;
}
