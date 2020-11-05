#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* direccion donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* es donde esta contenida la direccion de memoria de la lista
 * \return int -1 si hay error o 0 si anduvo bien
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* bufferEmployee;
	int retorno = -1;
	char auxId[4096];
	char auxNombre[4096];
	char auxHoras[4096];
	char auxSueldo[4096];

	if(pFile != NULL)
	{
		do
		{
			if (fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId,auxNombre ,auxHoras ,auxSueldo)== 4)
			{
				printf("%s, %s, %s, %s\n", auxId, auxNombre, auxHoras, auxSueldo);
				bufferEmployee = employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo);
				if(bufferEmployee != NULL)
				{
					ll_add(pArrayListEmployee, bufferEmployee);
				}
			}

		}while(feof(pFile) == 0);
		retorno = 0;
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char* direccion donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* es donde esta contenida la direccion de memoria de la lista
 * \return int -1 si hay error o 0 si anduvo bien
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* bufferEmployee;
	int retornoLectura;

	if(pFile != NULL)
	{
		do
		{
			bufferEmployee = employee_new();
			if(bufferEmployee != NULL)
			{
				retornoLectura =fread(bufferEmployee,sizeof(Employee),1,pFile);
				if(retornoLectura == 1)
				{
					ll_add(pArrayListEmployee,bufferEmployee);
				}
				else
				{
					employee_delete(bufferEmployee);
				}

			}

		}while(feof(pFile) == 0);

		retorno = 0;
	}
	return retorno;
}
