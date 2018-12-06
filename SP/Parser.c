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

//RECUPERATORIO SEGUNDO PARCIAL

int parser_parserVendedores(char* fileName, LinkedList* listaEmpleados)
{
//aca hacer el parser del archivo
    char Auxid;
    char Auxnombre[128];
    char Auxnivel;
    char AuxcantidadProductos;
    char AuxmontoVendido;

    int cant;
    int retorno;

    eVendedor*pVendedor;

    int flag = 0;
    int cont=0;

    FILE* pFile;
    pFile = fopen(fileName, "r");      //lectura texto

    if (pFile!=NULL)
    {
        printf("\n1");
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", Auxid, Auxnombre, Auxnivel,AuxcantidadProductos,AuxmontoVendido);
        printf("\n5");
        while(!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", Auxid, Auxnombre, Auxnivel,AuxcantidadProductos,AuxmontoVendido);
            //printf("\n%s    %s  ", Auxid, Auxnombre);

            if(cant == 5 && flag)
            {
                pVendedor = employee_newParametrosVendedor(Auxid, Auxnombre, Auxnivel,AuxcantidadProductos,AuxmontoVendido);
                if(pVendedor != NULL)
                {
                    ll_add(listaEmpleados, pVendedor);
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




