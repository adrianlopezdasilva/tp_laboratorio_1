#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
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

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pEmployee;

	if(pFile != NULL)
	{
		do
		{
			pEmployee = employee_new();
			fread(pEmployee,sizeof(Employee),1,pFile);
			ll_add(pArrayListEmployee,pEmployee);

		}while(feof(pFile) == 0);

		retorno = 0;
	}
	return retorno;
}
