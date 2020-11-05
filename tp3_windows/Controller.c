#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		if((utn_getNombre("\nIngrese el nombre del empleado: ", "\nEse no es un nombre valido\n", bufferNombre, 2,SIZENOMBRE) == 0) &&
		   (utn_getNumero("\nIngrese las horas trabajadas del empleado: ", "\nEsa no es una cantidad de horas valida\n", &bufferHoras, 2,0,MAXIMOHORAS) == 0) &&
		   (utn_getNumero("\nIngrese el sueldo del empleado: ", "\nEse no es un sueldo valido\n", &bufferSueldo, 2,0,MAXIMOSUELDO) == 0))
		{
			if(employee_setNombre(bufferEmployee, bufferNombre)==0 &&
			   employee_setHorasTrabajadas(bufferEmployee, bufferHoras)==0 &&
			   employee_setSueldo(bufferEmployee, bufferSueldo)==0 )
			{
				ll_add(pArrayListEmployee, bufferEmployee);
				retorno = 0;
			}
		}
		else
		{
			printf("\nSurgio un error durante la alta\n");
		}
	}

    return retorno;
}
/*
int controller_nextId(LinkedList* pArrayListEmployee)
{
	Employee* bufferEmployee;
	int auxId;
	int retorno = -1;

	if(pArrayListEmployee != NULL)
	{
		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			bufferEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(pArrayListEmployee, &auxId);
			if(auxId)
			{

			}
		}
	}

	return 0;
} */
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
  int retorno = -1;
  int auxId;
  Employee* bufferEmployee;
  char auxNombre[SIZENOMBRE];
  int auxHoras;
  int auxSueldo;
  int opcion;

  if(pArrayListEmployee != NULL)
  {
	  if(controller_ListEmployee(pArrayListEmployee) == 0 &&
	     utn_getNumero("\nIngrese el id del empleado que desea modifcar: ", "\nEse no es un id valido\n",
		 &auxId, 2,1,99999) == 0 )
	  {
		  auxId = auxId-1;
		  bufferEmployee = ll_get(pArrayListEmployee,auxId);
		  if(employee_getNombre(bufferEmployee, auxNombre) == 0 &&
		     employee_getHorasTrabajadas(bufferEmployee, &auxHoras) == 0 &&
			 employee_getSueldo(bufferEmployee, &auxSueldo) == 0 )
		  {
			  do
			  {
				  printf("\nEl employee a modificar es:\nNOMBRE: %s    -  HORAS TRABAJADAS: %d   SUELDO - %d\n",
						  auxNombre, auxHoras, auxSueldo);
				  if(utn_getNumero("\nQue campo desea modificar?\n1.Nombre.\n2.Horas Trabajadas.\n3.Sueldo.\n4.Salir.\n",
				  				"\nEse no es un id valido\n",  &opcion, 2,1,4) == 0 )
				  {
					  switch(opcion)
					  {
					  case 1:
					  		if(utn_getNombre("\nIngrese el nuevo nombre del empleado: ",
					  		   "\nEse no es un nombre valido\n", auxNombre, 2,SIZENOMBRE) == 0)
					  		{
					  			employee_setNombre(bufferEmployee,auxNombre);
					  		}
					  		break;
					  case 2:
						    if(utn_getNumero("\nIngrese las nuevas horas trabajadas del empleado: ",
						     "\nEsa no es una cantidad de horas valida\n", &auxHoras, 2,0,MAXIMOHORAS) == 0)
						    {
							  employee_setHorasTrabajadas(bufferEmployee,auxHoras);
						    }
						    break;
					  case 3:
						    if(utn_getNumero("\nIngrese el nuevo salario del empleado: ",
								     "\nEse no es un salario valido\n", &auxSueldo, 2,0,MAXIMOSUELDO) == 0)
						    {
						    	employee_setSueldo(bufferEmployee,auxSueldo);
						    }
						  	break;
					  }
				  }
			  }while(opcion != 4);
			  retorno = 0;
		  }
	  }
  }
  return retorno;
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
    int retorno = -1;
    int auxId;
    int flagBorrar = 1;
    int idABorrar;
    Employee* bufferEmployee;

    if(pArrayListEmployee != NULL)
    {
    	controller_ListEmployee(pArrayListEmployee);
    	if(utn_getNumero("\nIngrese el id del empleado que desea borrar: ", "\nEse no es un id valido\n",
		   &auxId, 2,1,99999) == 0)
    	{
    		auxId = auxId-1;
    		bufferEmployee = ll_get(pArrayListEmployee,auxId);
    		employee_getId(bufferEmployee, &idABorrar);

    		if(utn_getNumero("\nEsta seguro que quiere borrar este empleado?\n1.Abortar operacion.\n2.Confirmar borrar\n",
    						 "\nEse no es una opcion valida\n",&flagBorrar, 2,1,2) == 0 &&
    			flagBorrar == 2)
    		{
    			ll_remove(pArrayListEmployee, idABorrar);
    			printf("\nEmpleado eliminado con exito\n");
    		}
    		else
    		{
    			printf("\nOperacion abortada\n");
    		}
    		retorno = 0;
    	}
    }

    return retorno;
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
	Employee* bufferEmployee;
	int retorno = -1;
	int auxId;
	char auxNombre[SIZENOMBRE];
	int auxHoras;
	int auxSueldo;

	if(pArrayListEmployee != NULL)
	{
		printf("\n\nID    NOMBRE       HORAS     SUELDO"); //HEADER
		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			bufferEmployee = ll_get(pArrayListEmployee,i);
			employee_getId(bufferEmployee, &auxId);
			employee_getNombre(bufferEmployee, auxNombre);
			employee_getHorasTrabajadas(bufferEmployee, &auxHoras);
			employee_getSueldo(bufferEmployee, &auxSueldo);

			printf("\n%d   -    %s    -   %d      %d  ", auxId, auxNombre, auxHoras, auxSueldo);
		}
		retorno = 0;
	}
    return retorno;
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
	int retorno = -1;
	int opcion;

	if(pArrayListEmployee != NULL)
	{
		if(utn_getNumero("\nPor que criterio quiere ordenar? Ingrease un numero:"
				          "\n1. Ordenar por nombre."
						  "\n2. Ordenar por horas trabajadas."
						  "\n3. Ordenar por salario."
						  "\n4. Salir.\n", "\nEsa no es una copcion valida", &opcion, 3,1,4) == 0)
		{
			do
			{
				switch(opcion)
				{
				case 1:
						ll_sort(pArrayListEmployee,employee_compareByName, 1);
						break;
				case 2:
						ll_sort(pArrayListEmployee,employee_compareByHoursWorked, 1);
						break;
				case 3:
						ll_sort(pArrayListEmployee,employee_compareBySalary, 1);
						break;
				}
			}while(opcion != 4);
			retorno = 0;
		}
	}
    return retorno;
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
	FILE* pFile;
	Employee* bufferEmployee;
	int retorno = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"wb");
		if(pFile != NULL)
		{
			for(int i = 0; i < ll_len(pArrayListEmployee); i++)
			{
				bufferEmployee = (Employee*)ll_get(pArrayListEmployee,i);
				fwrite(bufferEmployee, sizeof(Employee), 1, pFile);
			}
			retorno = 0;
		}
		fclose(pFile);
	}
    return retorno;
}

