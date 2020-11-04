


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"

Employee* employee_new(void)
{
	return (Employee*)malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this = employee_new();
	int auxId;
	int auxHoras;
	int auxSueldo;

	auxId= atoi(idStr);
	auxHoras= atoi(horasTrabajadasStr);
	auxSueldo= atoi(sueldoStr);
	if(this != NULL)
	{
		if((employee_setId(this, auxId)) == 0 &&
			(employee_setNombre(this, nombreStr)) == 0 &&
			(employee_setHorasTrabajadas(this, auxHoras)) == 0 &&
			(employee_setSueldo(this, auxSueldo) == 0))
		{
			return this;
		}
	}
	return NULL;
}

void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(esUnNombreValido(nombre,SIZENOMBRE)== 1 ) // ESTA FUNCION BUSCA SI HAY UN ERROR
		{
			strncpy(this->nombre,nombre, sizeof(this->nombre));
			retorno = 0;
		}

	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre,this->nombre, SIZENOMBRE);
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas >0)
	{
		if(esNumerica(this, MAXIMOHORAS) == 1)
		{
			this->horasTrabajadas =horasTrabajadas;
			retorno = 0;
		}

	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo >0)
	{
		if(esNumerica(this, MAXIMOSUELDO) == 1)
		{
			this->sueldo =sueldo;
			retorno = 0;
		}
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_compareByName(void* thisOne , void* thisTwo)
{
	int retorno = 0;
	char nombreUno[SIZENOMBRE];
	char nombreDos[SIZENOMBRE];

	if(thisOne != NULL && thisTwo != NULL)
	{
		if(employee_getNombre(thisOne, nombreUno)== 0 &&
		   employee_getNombre(thisTwo, nombreDos) == 0)
		{
			if(strncmp(thisOne, thisTwo, SIZENOMBRE ) > 1)
			{
				retorno = 1;
			}
			else
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int employee_compareByHoursWorked(void* thisOne , void* thisTwo)
{
	int retorno = 0;
	int auxHorasUno;
	int auxHorasDos;

	if(thisOne != NULL && thisTwo != NULL)
	{
		if(employee_getHorasTrabajadas(thisOne, &auxHorasUno)== 0 &&
			employee_getHorasTrabajadas(thisTwo, &auxHorasDos) == 0)
		{
			if(auxHorasUno > auxHorasDos)
			{
				retorno = 1;
			}
			else
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int employee_compareBySalary(void* thisOne , void* thisTwo)
{
	int retorno = 0;
	int auxSalarioUno;
	int auxSalarioDos;

	if(thisOne != NULL && thisTwo != NULL)
	{
		if(employee_getHorasTrabajadas(thisOne, &auxSalarioUno)== 0 &&
			employee_getHorasTrabajadas(thisTwo, &auxSalarioDos) == 0)
		{
			if(auxSalarioUno > auxSalarioDos)
			{
				retorno = 1;
			}
			else
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}


