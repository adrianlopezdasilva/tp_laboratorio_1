#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option;
    int flagCargaArchivo = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
    	if(utn_getNumero("\n\nMenu de opciones"
    					 "\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
    					 "\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
    					 "\n3. Alta de empleado"
    					 "\n4. Modificar datos de empleado"
    					 "\n5. Baja de empleado"
    					 "\n6. Listar empleados"
    					 "\n7. Ordenar empleados"
    					 "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
    					 "\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
    					 "\n10. Salir\n","Error,opcion invalida\n",&option, 20, 1, 10)== 0)
    	{
    		switch(option)
    		{
    		case 1:
    				if(flagCargaArchivo == 0)
    				{
    					controller_loadFromText("data.csv",listaEmpleados);
    					flagCargaArchivo = 1;
    				}
    				else
    				{
    					printf("\nEl archivo ya fue cargado.");
    				}

    				break;

    		case 2:
    				if(flagCargaArchivo == 0)
    			    {
    					controller_loadFromBinary("data.bin",listaEmpleados);
    			    	flagCargaArchivo = 1;
    			    }
    			    else
    			    {
    			    	printf("\nEl archivo ya fue cargado.");
    			    }
    				break;
    		case 3:
    				if(flagCargaArchivo == 1)
    				{
    					if(controller_addEmployee(listaEmpleados) == 0)
    					 {
    						printf("\nEmpleado cargado exitosamente");
    					 }
    				}
    				else
    				{
    					printf("\nPrimero debe cargar el archivo.");
    				}
    				break;
    		case 6:
    		    	if(flagCargaArchivo == 1)
    		    	{
    		    		if(controller_ListEmployee(listaEmpleados) == 0)
    		    		{
    		    			printf("\nOperacion lograda exitosamente");
    		    		}
    		    	}
    		    	else
    		    	{
    		    		printf("\nPrimero debe cargar el archivo.");
    		    	}
    		        break;

    		case 7:
    				if(flagCargaArchivo == 1)
    			    {
    			    	if(controller_sortEmployee(listaEmpleados) == 0)
    			    	{
    			    		printf("\nOperacion lograda exitosamente");
    			    	}
    			    }
    			    else
    			    {
    			    	printf("\nPrimero debe cargar el archivo.");
    			    }
    				break;
    		case 8:
    				if(flagCargaArchivo == 1)
    			    {
    			    	if(controller_saveAsText("data.csv",listaEmpleados) == 0)
    			    	{
    			    		printf("\nOperacion lograda exitosamente");
    			    	}
    			    }
    			    else
    			    {
    			    	printf("\nPrimero debe cargar el archivo.");
    			    }
    			    break;
    		case 9:
    		    	if(flagCargaArchivo == 1)
    		    	{
    		    		if(controller_saveAsBinary("data.bin",listaEmpleados) == 0)
    		    		{
    		    		printf("\nOperacion lograda exitosamente");
    		    		}
    		    	}
    		    	else
    		    	{
    		    		printf("\nPrimero debe cargar el archivo.");
    		    	}
    		    	break;
    		}

    	}
    }while(option != 10);
    return 0;
}
