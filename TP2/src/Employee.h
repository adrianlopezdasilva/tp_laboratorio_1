/*
 * Employee.h
 *
 *  Created on: 2020/10/02
 *      Author: PC
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#define TRUE 1
#define FALSE 0

typedef struct
{
	int id;
	int isEmpty;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
}Employee;

int initEmployees(Employee* list, int len);
int employee_buscarLibreRef (Employee* list, int len, int * pIndice);
int addEmployee(Employee* list, int len);
int findEmployeeById(Employee* list, int len,int id, int* pIndice);
int modifyEmployee(Employee* list, int len);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
int removeEmployee(Employee* list, int len);
int salarioTotalYPromedio(Employee* list, int len);

#endif /* EMPLOYEE_H_ */
