#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    FILE* pFile = fopen(path,"r");
    if(pFile !=NULL)
    {
    	parser_EmployeeFromText(pFile,pArrayListEmployee);
    	retorno = 1;
    }
    fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    FILE* pFile=fopen(path,"rb");
    if(pFile !=NULL)
    {
    	parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    	retorno = 1;
    }
    fclose(pFile);

    return retorno;
}
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	Employee* bufferEmployee = employee_new();
	char bufferNombre[SIZENOMBRE];
	int bufferHoras;
	int bufferSueldo;

	if(pArrayListEmployee != NULL)
	{
		if((utn_getNombre("Ingrese el nombre del empleado: ", "\nEse no es un nombre valido", bufferNombre, 2,SIZENOMBRE) == 0) &&
		   (utn_getNumero("Ingrese las horas trabajadas del empleado: ", "\nEsa no es una cantidad de horas valida", &bufferHoras, 2,0,MAXIMOHORAS) == 0) &&
		   (utn_getNumero("Ingrese el sueldo del empleado: ", "\nEse no es un sueldo valido", &bufferSueldo, 2,0,MAXIMOSUELDO) == 0))
		{
			employee_setNombre(bufferEmployee, bufferNombre);
			employee_setHorasTrabajadas(bufferEmployee, bufferHoras);
			employee_setSueldo(bufferEmployee, bufferSueldo);
			ll_add(pArrayListEmployee, bufferEmployee);

			retorno = 0;
		}
		else
		{
			printf("\nSurgio un error durante la alta\n");
		}
	}

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* bufferEmployee;
	FILE* pFile;
	int auxId;
	char auxNombre[SIZENOMBRE];
	int auxHoras;
	int auxSueldo;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"w");
		{
			if(pFile != NULL)
			{
				for(int i = 0; i < ll_len(pArrayListEmployee); i++)
				{
					bufferEmployee = ll_get(pArrayListEmployee,i);
					if(employee_getId(bufferEmployee,&auxId )== 0  &&
					   employee_getNombre(bufferEmployee,auxNombre) == 0 &&
					   employee_getHorasTrabajadas(bufferEmployee,&auxHoras) == 0 &&
					   employee_getSueldo(bufferEmployee,&auxSueldo) == 0 )
					{
						fprintf(pFile,"%d, %s, %d, %d\n",auxId, auxNombre, auxHoras,auxSueldo);
					}

				}
				retorno = 0;
				fclose(pFile);
			}
		}
	}
	 return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{

	}
    return retorno;
}
