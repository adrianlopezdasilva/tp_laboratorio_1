


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"


static int isValidSueldo (int sueldo);
static int isValidHorasTrabajadas(int horas);

/** \brief Crea un nuevo employee
 *
 * \param void LinkedList* es donde esta contenida la direccion de memoria de la lista
 * \return Employee* en caso de que salga bien, NULL de lo contrario
 *
 */
Employee* employee_new(void)
{

	Employee* bufferEmployee;
	bufferEmployee = (Employee*)malloc(sizeof(Employee));
	if(bufferEmployee == NULL)
	{
		printf("\nLa lista esta llena\n");
	}
	return bufferEmployee;
}

/** \brief Crea un nuevo employee, pasandole el valor de los campos como parametro
 *
 *\param idStr char* string que contiene el id a utilizar
 *\param nombreStr char* string que contiene el nombre a utilizar
 *\param horasTrabajadasStr char* string que contiene las horas trabajadas a utilizar
 *\param sueldoStr char* string que contiene el sueldo a utilizara
 *
 * \return Employee* en caso de que salga bien, NULL de lo contrario
 *
 */
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

/** \brief Elimina un empleado
 *
 * \param this Employee* el employee a borrar
 * \return void
 */
void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

/** \brief Fija el id de un empleado
 *
 * \param this Employee* el employee a utilizar
 * \param id int el id a fijar
 *
 * \return -1 si hay error, 0 si funciona bien
 */

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
/** \brief Obtiene el id de un empleado
 *
 * \param this Employee* el employee a utilizar
 * \param id int* el id obtenido
 *
 * \return -1 si hay error, 0 si funciona bien
 */
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

/** \brief Fija el nombre de un empleado
 *
 * \param this Employee* el employee a utilizar
 * \param nombre char* el nombre a fijar
 *
 * \return -1 si hay error, 0 si funciona bien
 */
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

/** \brief Obtiene el nombre de un empleado
 *
 * \param this Employee* el employee a utilizar
 * \param nombre char* el nombre obtenido
 *
 * \return -1 si hay error, 0 si funciona bien
 */
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

/** \brief Fija las horas trabajadas de un empleado
 *
 * \param this Employee* el employee a utilizar
 * \param horasTrabajadas int las horas trabajadas a fijar
 *
 * \return -1 si hay error, 0 si funciona bien
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas >0)
	{
		if(isValidHorasTrabajadas(horasTrabajadas) == 1)
		{
			this->horasTrabajadas =horasTrabajadas;
			retorno = 0;
		}

	}
	return retorno;
}
/** \brief Obtiene las horas trabajadas de un empleado
 *
 * \param this Employee* el employee a utilizar
 * \param horasTrabajadas int* las horas trabajadas obtenidas
 *
 * \return -1 si hay error, 0 si funciona bien
 */
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

/** \brief Fija el sueldo  de un empleado
 *
 * \param this Employee* el employee a utilizar
 * \param sueldo int el sueldo a fijar
 *
 * \return -1 si hay error, 0 si funciona bien
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo >0)
	{
		if(isValidSueldo(sueldo) == 1)
		{
			this->sueldo =sueldo;
			retorno = 0;
		}
	}
	return retorno;
}
/** \brief Obtiene el sueldo de un empleado
 *
 * \param this Employee* el employee a utilizar
 * \param sueldo int* el sueldo obtenido
 *
 * \return -1 si hay error, 0 si funciona bien
 */
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
/** \brief Compara la lista de empleados segun su nombre
 *
 * \param thisOne void* El primer campo a comprar
 * \param thisTwo void* El segundo campo a comprar
 *
 * \return 1 si el primer campo es mas grande o -1 de lo contrario, 0 si hay error
 */
int employee_compareByName(void* thisOne , void* thisTwo)
{
	int retorno = 0;
	char nombreUno[SIZENOMBRE];
	char nombreDos[SIZENOMBRE];

	Employee* bufferEmpleadoUno;
	Employee* bufferEmpleadoDos;

	bufferEmpleadoUno = (Employee*) thisOne;
	bufferEmpleadoDos = (Employee*) thisTwo;

	if(thisOne != NULL && thisTwo != NULL)
	{
		if(employee_getNombre(bufferEmpleadoUno, nombreUno)== 0 &&
		   employee_getNombre(bufferEmpleadoDos, nombreDos) == 0)
		{
			if(strncmp(nombreUno, nombreDos, SIZENOMBRE ) > 0)
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

/** \brief Compara la lista de empleados segun sus horas trabajadas
 *
 * \param thisOne void* El primer campo a comprar
 * \param thisTwo void* El segundo campo a comprar
 *
 * \return 1 si el primer campo es mas grande o -1 de lo contrario, 0 si hay error
 */
int employee_compareByHoursWorked(void* thisOne , void* thisTwo)
{
	int retorno = 0;
	int auxHorasUno;
	int auxHorasDos;

	Employee* bufferEmpleadoUno;
	Employee* bufferEmpleadoDos;

	bufferEmpleadoUno = (Employee*) thisOne;
	bufferEmpleadoDos = (Employee*) thisTwo;

	if(thisOne != NULL && thisTwo != NULL)
	{
		if(employee_getHorasTrabajadas(bufferEmpleadoUno, &auxHorasUno)== 0 &&
			employee_getHorasTrabajadas(bufferEmpleadoDos, &auxHorasDos) == 0)
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
/** \brief Compara la lista de empleados segun su salario
 *
 * \param thisOne void* El primer campo a comprar
 * \param thisTwo void* El segundo campo a comprar
 *
 * \return 1 si el primer campo es mas grande o -1 de lo contrario, 0 si hay error
 */
int employee_compareBySalary(void* thisOne , void* thisTwo)
{
	int retorno = 0;
	int auxSalarioUno;
	int auxSalarioDos;

	Employee* bufferEmpleadoUno;
	Employee* bufferEmpleadoDos;

	bufferEmpleadoUno = (Employee*) thisOne;
	bufferEmpleadoDos = (Employee*) thisTwo;

	if(thisOne != NULL && thisTwo != NULL)
	{
		if(employee_getHorasTrabajadas(bufferEmpleadoUno, &auxSalarioUno)== 0 &&
			employee_getHorasTrabajadas(bufferEmpleadoDos, &auxSalarioDos) == 0)
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

/** \brief Valida que el sueldo este dentro de los rangos aceptables
 *
 * \param sueldo int El sueldo a validad
 * \return -1 si hay error, 1 si funciona bien
 */
static int isValidSueldo (int sueldo)
{
	int retorno = 1;

	if(sueldo < 0 || sueldo > MAXIMOSUELDO)
	{
		retorno = -1;
	}

	return retorno;
}

/** \brief Valida que las horas trabajadas este dentro de los rangos aceptables
 *
 * \param sueldo int El sueldo a validad
 * \return -1 si hay error, 1 si funciona bien
 */
static int isValidHorasTrabajadas(int horas)
{
	int retorno = 1;

	if(horas < 0 || horas > MAXIMOHORAS)
	{
		retorno = -1;
	}

	return retorno;
}
