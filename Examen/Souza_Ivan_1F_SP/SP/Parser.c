#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
//aca hacer el parser del archivo
    Empleado*pEmpleadoAux;
    int cant;
    int retorno=0;
    char idAux[2000];
    char nombreAux[2000];
    char horasAux[2000];
    int flag = 0;
    int cont=0;

    FILE* pFile;
    pFile = fopen(fileName, "r");      //lectura texto

    if (pFile!=NULL)
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasAux);

        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasAux);
            printf("\n%s    %s     %s", idAux, nombreAux, horasAux);

            if(cant == 3 && flag)
            {
                pEmpleadoAux = employee_newParametros(idAux, nombreAux, horasAux);
                if(pEmpleadoAux != NULL)
                {
                    ll_add(listaEmpleados, pEmpleadoAux);
                    retorno = 1;
                }
            }
            flag = 1;
        }
    }
    else
    {
        printf("\nEl archivo no existe");
    }
    return retorno;
}
