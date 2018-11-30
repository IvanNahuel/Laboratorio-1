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
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char idAux[2000];
    char nombreAux[2000];
    char horasAux[2000];
    char sueldoAux[2000];
    Employee* employeeAux;
    int cant;
    int retorno = 0;

    cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasAux, sueldoAux);

    while(!feof(pFile))
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasAux, sueldoAux);

        if(cant == 4)
        {
            employeeAux = employee_newParametros(idAux, nombreAux, horasAux, sueldoAux);
            if(employeeAux != NULL)
            {
                ll_add(pArrayListEmployee, employeeAux);
                retorno = 1;
            }
        }
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
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* employeAux;
    int cant;
    int retorno = 0;

    while(!feof(pFile))
    {
        employeAux = employee_new();
        cant = fread(employeAux, sizeof(Employee), 1, pFile);

        if(employeAux != NULL && cant == 1)
        {
            ll_add(pArrayListEmployee, employeAux);
            retorno = 1;
        }
    }

    return retorno;
}
