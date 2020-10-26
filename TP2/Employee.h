#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} typedef Employee;

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
void mostrarEmpleado (Employee x);
void ordenarEmpleados (Employee vec[], int QTY);
void mostrarEmpleados (Employee vec[], int QTY);
void ordenarEmpleados (Employee vec[], int QTY);
int buscarLibre (Employee vec[], int tam);
void  modificarEmpleado(Employee vec[], int qty);
void hardcordearEmpleados(Employee vec[], int cant);



#endif // EMPLOYEE_H_INCLUDED
