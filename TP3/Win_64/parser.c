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
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
    //levanta los datos y los convierte en sus respectivos TIPOS DE DATOS
    char var1[50],var3[50],var2[50],var4[50];
    int r;
    int flag=0;

do{
    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

    if(r==4 && flag==1){
    Initialize(&arrayPersonas[i],atoi(var4),var3,var2 ,atoi(var1));
    i++;
    }

    else if (r!=4&&flag==1){
        break;
    }
    flag=1;

    }while(!feof(pFile));

    return 1;
}
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){

    return 1;
}
