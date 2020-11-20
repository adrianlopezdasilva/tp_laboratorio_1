/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"
#define CANTIDAD_CLIENTES 5

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int opcionInformes;
	int flagOrdenamiento;
	int flagArrayVacio = 0;

	Employee empleados[CANTIDAD_CLIENTES];

	initEmployees(empleados,CANTIDAD_CLIENTES);
	do
	{
		if(utn_getNumero("\n\nMenu de opciones"
						 "\n1-Dar de alta un empleado "
						 "\n2-Modificar un empleado"
						 "\n3-Dar de baja un empleado"
						 "\n4-Informes"
						 "\n5-Salir\n","Error,opcion invalida\n",&opcion, 10, 1, 5)== 0)
		{
			switch(opcion)
			{
			case 1:
				if(addEmployee(empleados, CANTIDAD_CLIENTES) == 0)
				{
					flagArrayVacio = 1;
				}
				break;

			case 2:
				if(flagArrayVacio == 1)
				{
					modifyEmployee(empleados,CANTIDAD_CLIENTES);
				}
				else
				{
					printf("\nNo hay empleados para mostrar");
				}
				break;

			case 3:
				if(flagArrayVacio == 1)
				{
					removeEmployee(empleados,CANTIDAD_CLIENTES);
				}
				else
				{
					printf("\nNo hay empleados para mostrar");
				}
				break;
			case 4:
				if(flagArrayVacio == 1)
				{	do
					{
						if(utn_getNumero("\n\nMenu de informes"
										"\n1-Listado de los empleados ordenados alfabeticamente por Apellido y Sector."
										"\n2-Total y promedio de los salarios, y cuantos empleados superan el salario promedio."
										"\n3-Salir\n","Error,opcion invalida\n",&opcionInformes, 4, 1, 3)== 0)
						{
							switch(opcionInformes)
							{
							case 1:
								if(	utn_getNumero("\nDesea ordenar los empleados ascendetemente o descendientemente?\n 1: Ascendetemente.\n 2: Descendientemente\n",
												 "\nEsa no es una opcion valida",&flagOrdenamiento,5, 1, 2 )== 0)
								{
									sortEmployees(empleados, CANTIDAD_CLIENTES,flagOrdenamiento);
									printEmployees(empleados, CANTIDAD_CLIENTES);
								}
								else
								{
									printf("\nNo hay empleados para mostrar");
								}
								break;

							case 2:
								printEmployees(empleados, CANTIDAD_CLIENTES);
								salarioTotalYPromedio(empleados, CANTIDAD_CLIENTES);
								break;
							}

						}
					}while(opcionInformes != 3);
				}
				else
				{
					printf("\nNo hay ningun empleado para mostrar");
				}
					break;
			}
		}

	}while(opcion != 5);
}
