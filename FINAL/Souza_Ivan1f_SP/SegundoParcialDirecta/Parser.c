#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "utn.c"
#include "Parser.h"

int parser_envios(char* fileName, LinkedList* listaEnvios)
{
//aca hacer el parser del archivo
    eEnvios*pAuxEnvios;
    int cant;
    int retorno=0;

    char idAux[2000];
    char nombreProductos[2000];
    //char idCamionAux[2000];
    //char zonaDestinoAux[2000];
    char kmRecorridosAux[2000];
    char tipoEntregaAux[2000];

    int flag = 0;
    int cont=0;

    FILE* pFile;
    pFile = fopen("data.csv", "r");      //lectura texto

    if (pFile!=NULL)
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux,nombreProductos,kmRecorridosAux,tipoEntregaAux);

        while(!feof(pFile))
        {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux,nombreProductos,kmRecorridosAux,tipoEntregaAux);
            printf("\n%s    %s     ", idAux, nombreProductos);

            if(cant == 4 && flag)
            {
                pAuxEnvios = envios_newParametros(idAux,nombreProductos,kmRecorridosAux,tipoEntregaAux);

                if (pAuxEnvios!=NULL){
                    ll_add(listaEnvios,pAuxEnvios);
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
