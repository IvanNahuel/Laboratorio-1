#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Pide espacio de memoria para la estructura Employee
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{
    Employee* this = malloc(sizeof(Employee));

    return this;
}


/** \brief pide espacio de memoria y guarda todos los datos en la estructura
 *
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldoStr
 * \return Employee
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* empNew;
    Employee* returnEmp;
    int id;
    int horasTrabajadas;
    int sueldo;
    empNew = employee_new();

    if(empNew != NULL)
    {
        id = atoi(idStr);
        horasTrabajadas = atoi(horasTrabajadasStr);
        sueldo = atoi(sueldoStr);

        if(employee_setId(empNew, id) == 1 &&
                employee_setNombre(empNew, nombreStr) == 1 &&
                employee_setHorasTrabajadas(empNew, horasTrabajadas) == 1 &&
                employee_setSueldo(empNew, sueldo) == 1)
        {
            returnEmp = empNew;
        }
    }
    return returnEmp;
}

/** \brief Guarda el id en la estructura Employee
 *
 * \param Employee* this
 * \param int id
 * \return int
 *
 */
int employee_setId(Employee* this,int id)
{
    int retorno = 0;
    static int nextId = -1;
    if(this != NULL)
    {
        if(id == -1)
        {
            nextId++;
            this->id = nextId;
            retorno = 1;
        }
        else if(id > nextId)
        {
            nextId = id;
            this->id = nextId;
            retorno = 1;
        }
    }
    return retorno;
}

/** \brief Guarda el nombre en la estructura Employee
 *
 * \param Employee* this
 * \param char* nombre
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre[0] != '\0')
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 1;
    }
    return retorno;
}

/** \brief Guarda la cantidad de horas en la estructura Employee
 *
 * \param Employee* this
 * \param int horasTrabajadas
 * \return itn
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

/** \brief Guarda el sueldo en la estructura Employee
 *
 * \param Employee* this
 * \param int sueldo
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = 0;

    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno = 1;
    }

    return retorno;
}

/** \brief Valor de tipo entero que se obtiene de la estructura
 *
 * \param Employee* this
 * \param int* id
 * \return int
 *
 */
int employee_getId(Employee* this,int* id)
{
    int retorno = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

/** \brief Valor de tipo cadena de caracteres que se obtiene de la estructura
 *
 * \param Employee* this
 * \param char* nombre
 * \return int
 *
 */

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 0;

    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 1;
    }

    return retorno;
}

/** \brief Valor de tipo entero que se obtiene de la estructura
 *
 * \param Employee* this
 * \param int* horasTrabajadas
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

/** \brief Valor de tipo entero que se obtiene de la estructura
 *
 * \param Employee* this
 * \param int* sueldo
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }

    return retorno;
}

/** \brief Libera el espacio de memoria de la estructura a eliminar
 *
 * \param Employee* this
 * \return Sin retorno
 */
void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

/** \brief añade un empleado nuevo a la lista
 *
 * \param LinkedList* pArrayEmployee
 * \return int
 */
int employee_empAddNew(LinkedList* pArrayEmployee)
{
    Employee* auxEmployee;
    int opcion, retorno = 0;
    char nombreAux[100];
    char bufferHoras[1000];
    char bufferId[1000] = "-1";
    char bufferSueldo[1000];
    int sueldoAux, horasAux;

    do
    {
        auxEmployee = employee_new();
        system("cls");
        printf("Alta de empleados.");
        printf("\n-----------------------");
        printf("\nIngrese los datos del empleado que desea dar de alta.");
        printf("\n\nIngrese el nombre del empleado: ");
        fflush(stdin);
        fgets(nombreAux, sizeof(nombreAux)-2, stdin);

        printf("\nIngrese la cantidad de horas trabajadas: ");
        fflush(stdin);
        scanf("%d", &horasAux);

        printf("\nIngrese el sueldo del empleado: ");
        fflush(stdin);
        scanf("%d", &sueldoAux);

        printf("\nDesea ingresar un nuevo empleado? 1= SI 2= NO");
        fflush(stdin);
        printf("\n\nOpcion seleccionada: ");
        scanf("%d", &opcion);

        sprintf(bufferHoras, "%d", horasAux);
        sprintf(bufferSueldo, "%d", sueldoAux);

        auxEmployee = employee_newParametros(bufferId, nombreAux, bufferHoras, bufferSueldo);

        if(auxEmployee != NULL)
        {
            ll_add(pArrayEmployee, auxEmployee);
            retorno = 1;
        }
    }
    while(opcion != 2);

    return retorno;
}
/** \brief Lista todos los empleados de la lista
 *
 * \param LinkedList* pArrayList
 * \return Sin retorno
 */
void employee_empList(LinkedList* pArrayList)
{
    Employee* auxEmployee;
    int i;
    int auxId;
    int auxHoras;
    int auxSueldo;
    char auxNombre[1000];
    int cantidad;

    cantidad = ll_len(pArrayList);
    system("cls");
    if(pArrayList != NULL)
    {
        for(i = 0; i < cantidad; i++)
        {
            auxEmployee = ll_get(pArrayList, i);

            if(employee_getId(auxEmployee, &auxId) == 1 &&
                    employee_getNombre(auxEmployee, auxNombre) == 1 &&
                    employee_getHorasTrabajadas(auxEmployee, &auxHoras) == 1 &&
                    employee_getSueldo(auxEmployee, &auxSueldo) == 1)
            {
                printf("\nID: %d   Nombre: %s   Horas Que Trabaja: %d   Sueldo: %d \n", auxId, auxNombre, auxHoras, auxSueldo);
                printf("-----------------------------------------------------------------------------");
            }
        }
        system("pause");
    }
}
/** \brief Quita un empleado de la lista en un indice especificado
 *
 * \param LinkedList* pArrayList
 * \return Sin retorno
 */

void employee_empRemove(LinkedList* pArrayList)
{
    Employee* auxEmployee;
    int i;
    int cantidad;
    int opcionUno;
    int opcionDos;
    int auxId;
    int indice = 0;

    cantidad = ll_len(pArrayList);

    do
    {
        system("cls");
        printf("Bajas de Empleados.");
        printf("\nIntroduzca el ID del empleado que desea dar de baja: ");
        fflush(stdin);
        scanf("%d", &auxId);

        if(pArrayList != NULL)
        {
            for(i = 0; i < cantidad; i++)
            {
                auxEmployee = ll_get(pArrayList, i);
                if(auxId == auxEmployee->id)
                {
                    printf("\n\nID: %d  Nombre: %s  horas que trabaja: %d  Sueldo: %d", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
                    printf("\n\nDesea eliminar el registro? 1= SI\n2= NO");
                    fflush(stdin);
                    scanf("%d", &opcionUno);
                    i = indice;
                    break;
                }
            }
            auxEmployee = ll_get(pArrayList, i);

            if(opcionUno == 1)
            {
                employee_delete(auxEmployee);
                ll_remove(pArrayList, indice);
                printf("Se han dado de baja los datos");
                system("pause");
            }
            else
            {
                printf("\nBaja cancelada");
                system("pause");
            }
        }

        printf("\n\nDesea eliminar el registro? 1= SI\n2= NO");
        fflush(stdin);
        scanf("%d", &opcionDos);

    }
    while(opcionDos != 2);
}
/** \brief Modifica un empleado de la lista en el indice especificado
 *
 * \param LinkedList* pArrayList
 * \return Sin retorno
 */
void employee_empEdit(LinkedList* pArrayList)
{
    Employee* auxEmployee;
    int i;
    int cantidad;
    int opcionUno;
    int opcionDos;
    int indice = 0;
    int auxId;
    int auxHoras;
    int auxSueldo;
    char auxNombre[1000];

    cantidad = ll_len(pArrayList);

    do
    {
        system("cls");
        printf("Modificacion de Empleados.");
        printf("\nIngrese ID a modificar");
        fflush(stdin);
        scanf("%d", &auxId);

        if(pArrayList != NULL)
        {
            for(i = 0; i < cantidad; i++)
            {
                auxEmployee = ll_get(pArrayList, i);

                if(auxId == auxEmployee->id)
                {
                    printf("\n\nID: %d  Nombre: %s  horas que trabaja: %d  Sueldo: %d", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
                    printf("\n\nDesea modificar el registro? 1= SI 2= NO");
                    printf("\n\nOpcion Seleccionada: ");
                    fflush(stdin);
                    scanf("%d", &opcionUno);
                    i = indice;
                    break;
                }
            }
            auxEmployee = ll_get(pArrayList, i);

            if(opcionUno == 1)
            {
                system("cls");
                printf("Modificar datos.");
                printf("\n-----------------------");
                printf("\n\nIngrese nuevo nombre: ");
                fflush(stdin);
                fgets(auxNombre, sizeof(auxNombre)-2, stdin);
                printf("\nIngrese nueva cantidad de horas: ");
                fflush(stdin);
                scanf("%d", &auxHoras);
                printf("\nIngrese nuevo salario: ");
                fflush(stdin);
                scanf("%d", &auxSueldo);

                strcpy(auxEmployee->nombre, auxNombre);
                auxEmployee->horasTrabajadas = auxHoras;
                auxEmployee->sueldo = auxSueldo;

                printf("\nDatos modificados");
                system("pause");
            }
        }
        printf("\n\nDesea modificar otro dato? 1= SI\n2= NO\n");
        fflush(stdin);
        scanf("%d", &opcionDos);

    }
    while(opcionDos != 2);
}

/** \brief Criterio de ordenamiento
 *
 * \param void* nombreUno
 * \param void* nombreDos
 * \return Sin retorno
 */

int employee_empOrderList(void* nombreUno, void* nombreDos)
{
    int retorno = 0;
    char nombreY[1000];
    char nombreZ[1000];

    employee_getNombre((Employee*)nombreUno,nombreY);
    employee_getNombre((Employee*)nombreDos,nombreZ);

    if(strcmp(nombreY,nombreZ) > 0)
    {
        retorno = 1;
    }

    if(strcmp(nombreY,nombreZ) < 0)
    {
        retorno = 2;
    }
    return retorno;
}

/** \brief Guarda toda la lista en un archivo de texto
 * \param char* path
 * \param LinkedList* pArrayList
 * \return int
 */
int employee_empSaveText(char* path, LinkedList* pArrayList)
{
    int i, cantidad, retorno = 0;
    FILE* pFile;
    Employee* auxEmployee;

    pFile = fopen(path, "w");
    cantidad = ll_len(pArrayList);

    if(pFile != NULL)
    {
        for(i = 0; i < cantidad; i++)
        {
            auxEmployee = ll_get(pArrayList, i);
            fprintf(pFile, "%d,%s,%d,%d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
        }

        retorno = 1;
    }

    fclose(pFile);

    return retorno;
}

/** \brief Guarda toda la lista en un archivo binario
 * \param char* path
 * \param LinkedList* pArrayList
 * \return int
 */
int employee_empSaveBinari(char* path, LinkedList* pArrayList)
{
    int i, cantidad, retorno = 0;
    FILE* pBinFile;
    Employee* auxEmployee;

    pBinFile = fopen(path, "wb");
    cantidad = ll_len(pArrayList);

    if(pBinFile != NULL)
    {
        for(i = 0; i < cantidad; i++)
        {
            auxEmployee = ll_get(pArrayList, i);
            fwrite(auxEmployee,sizeof(Employee),1,pBinFile);
        }

        retorno = 1;
    }

    fclose(pBinFile);

    return retorno;
}
